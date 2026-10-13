#!/bin/sh
# Build & install the headless QA tools OUTSIDE the repo:
#   $PREFIX/bin/mgba-rom-test        (runner used by `make check`)
#   $PREFIX/bin/mgba-rom-test-hydra  (parallel driver used by `make check`)
#   $PREFIX/bin/gbaplay              (scripted headless player, tools/qa/gbaplay)
#   $PREFIX/lib/libmgba.a + headers  (static libmgba, no Qt/SDL/GL)
# Usage: tools/qa/install_mgba_tools.sh [PREFIX]   (default /opt/mgba-tools)
# Deps (Ubuntu): sudo apt-get install -y cmake ninja-build pkg-config libpng-dev zlib1g-dev libelf-dev libzstd-dev
set -e
PREFIX=${1:-/opt/mgba-tools}
SRC=${MGBA_SRC:-/opt/mgba-src}
# Same mGBA commit as the prebuilt Linux tools/mgba/mgba-rom-test shipped by the expansion (tools/mgba/README.md)
MGBA_COMMIT=${MGBA_COMMIT:-dbffb46c4e7d2e7a2cbed7c3488cece4c2176d4c}
REPO=$(cd "$(dirname "$0")/../.." && pwd)
JOBS=${JOBS:-$(nproc)}

mkdir -p "$SRC"
if [ ! -d "$SRC/mgba/.git" ]; then
    git clone https://github.com/mgba-emu/mgba.git "$SRC/mgba"
fi
git -C "$SRC/mgba" fetch -q origin || true
git -C "$SRC/mgba" checkout -q "$MGBA_COMMIT"

cmake -S "$SRC/mgba" -B "$SRC/mgba/build" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$PREFIX" \
    -DBUILD_QT=OFF -DBUILD_SDL=OFF -DBUILD_GL=OFF -DBUILD_GLES2=OFF -DBUILD_GLES3=OFF -DUSE_EPOXY=OFF \
    -DUSE_FFMPEG=OFF -DUSE_LIBZIP=OFF -DUSE_MINIZIP=OFF -DUSE_LZMA=OFF -DUSE_DISCORD_RPC=OFF \
    -DUSE_LUA=OFF -DUSE_EDITLINE=OFF -DUSE_GDB_STUB=OFF -DUSE_SQLITE3=OFF \
    -DBUILD_ROM_TEST=ON -DBUILD_STATIC=ON -DBUILD_SHARED=OFF -DBUILD_LTO=OFF
ninja -C "$SRC/mgba/build" -j"$JOBS"
ninja -C "$SRC/mgba/build" install

# Defines libmgba was compiled with: programs including mGBA internal headers MUST use the
# same ones (struct layouts depend on e.g. USE_PTHREADS), otherwise memory gets corrupted.
ninja -C "$SRC/mgba/build" -t commands mgba | grep "src/gba/core.c" | head -1 | tr ' ' '\n' \
    | grep '^-D' | grep -v 'NDEBUG\|BUILD_STATIC' | sort -u | tr '\n' ' ' > "$PREFIX/lib/mgba-cflags.txt"

cc "$REPO/tools/mgba-rom-test-hydra/main.c" -Werror=implicit-function-declaration -o "$PREFIX/bin/mgba-rom-test-hydra" -lm
make -C "$REPO/tools/qa/gbaplay" MGBA_PREFIX="$PREFIX" CC=cc
echo "Installed in $PREFIX/bin:"; ls -l "$PREFIX/bin"
