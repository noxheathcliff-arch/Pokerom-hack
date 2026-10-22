# cf_doctor sprites

Sprites of the green-haired doctor, redrawn over existing game sprites
(recolour + pixel patches), never from scratch:

| Output | Base sprite(s) |
|---|---|
| `graphics/trainers/front_pics/cf_doctor.png` (64x64) | `front_pics/steven.png` |
| `graphics/trainers/back_pics/cf_doctor.png` (64x256, 4 throw frames) | `back_pics/steven.png` |
| `graphics/object_events/pics/people/cf_doctor.png` (144x32, 9 frames) | head of `people/steven.png` + lab-coat body of `people/scientist_1.png` |

Run from the repository root: `tools/sprites/cf_doctor/build.sh`.
In game: `TRAINER_PIC_CF_DOCTOR` (trainer pic, front + back) and `OBJ_EVENT_GFX_CF_DOCTOR` (overworld).
