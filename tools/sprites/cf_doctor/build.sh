#!/bin/sh
# Regenerate the three cf_doctor PNGs from the base game sprites (run from the repo root).
set -e
D=tools/sprites/cf_doctor
python3 $D/make_front.py graphics/trainers/front_pics/cf_doctor.png
python3 $D/make_back.py graphics/trainers/back_pics/cf_doctor.png
python3 $D/make_ow.py graphics/object_events/pics/people/cf_doctor.png
