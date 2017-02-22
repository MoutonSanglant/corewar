.name       "UltraKillerLord"
.comment    "Ultrakilling you"

wall:
st  r4, -320
st  r4, -321
st  r4, -322
st  r4, -323
st  r4, -324
st  r4, -325
st  r4, -326
st  r4, -327
st  r4, -328
st  r4, -329
st  r4, -330
st  r4, -331
st  r4, -332
st  r4, -333
st  r4, -334
st  r4, -335
st  r4, -336
st  r4, -337
st  r4, -338
st  r4, -339
st  r4, -340
st  r4, -341
st  r4, -342
st  r4, -343
st  r4, -344
st  r4, -345
st  r4, -346
st  r4, -347
st  r4, -348
st  r4, -349
st  r4, -350
st  r4, -351
st  r4, -352
st  r4, -353
st  r4, -354
st  r4, -355
st  r4, -356
st  r4, -357
st  r4, -358
st  r4, -359
st  r4, -360
st  r4, -361
st  r4, -362
st  r4, -363
st  r4, -364
st  r4, -365
st  r4, -366
st  r4, -367
st  r4, -368
st  r4, -369
st  r4, -370
st  r4, -371
st  r4, -372
st  r4, -373
st  r4, -374
st  r4, -375
st  r4, -376
st  r4, -377
st  r4, -378
st  r4, -379
st  r4, -380
st  r4, -381
st  r4, -382
st  r4, -383
st  r4, -384
st  r4, -385
st  r4, -386
st  r4, -387
st  r4, -388
st  r4, -389
st  r4, -390
st  r4, -391
st  r4, -392
st  r4, -393
st  r4, -394
st  r4, -395
st  r4, -396
st  r4, -397
st  r4, -398
st  r4, -399

ld  16, r2
st  r1, 6
live    %0
add r2, r2, r2
fork %:forever_alive

add r4, r4, r4
zjmp %:wall

forever_alive:
st  r4, -12
st  r1, 6
live    %0
add r4, r4, r4
zjmp %:forever_alive
