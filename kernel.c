void _start()
{
    unsigned char *video = (unsigned char*)0xA0000;

    for(int i = 0; i < 320*200; i++)
    {
        video[i] = 4;   // red screen
    }

    while(1) { }
}
