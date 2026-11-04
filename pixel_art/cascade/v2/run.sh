set -e
python3 ../trace.py NEW:64x64:. v02_silhouette.txt c02_silhouette.txt
python3 ../trace.py v02_silhouette.txt v03a_zones.txt c03a_zones.txt
python3 ../contour.py v03a_zones.txt v03_contour.txt K .WZC
for f in "$@"; do :; done
