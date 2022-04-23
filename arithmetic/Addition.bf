,           ; read character a and store it in p1
>           ; move to next byte p2
,           ; read character b and store it in p2
[           ; start the while loop
    <       ; move to p1
    +       ; increment p1
    >       ; move back to p2
    -       ; decrement p2
]           ; exit the while loop when p2 is equal to zero
<           ; move back to p1
------------------------------------------------ ; subtract 48 (due to ascii) for char to int
.           ; print the sum