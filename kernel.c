void _start()
{
    char *video = (char*)0xB8000;

    video[0] = 'O';
    video[1] = 0x0F;

    video[2] = 'S';
    video[3] = 0x0F;

    video[4] = ' ';
    video[5] = 0x0F;

    video[6] = 'O';
    video[7] = 0x0F;

    video[8] = 'K';
    video[9] = 0x0F;

    while(1){}
}
