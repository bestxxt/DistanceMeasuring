#include <DistanceMeasure.h>

void Draw_Slow_Bitmap(int x, int y, const unsigned char* bitmap, unsigned char w, unsigned char h)
{
    uint8_t color = Disp.getDrawColor();
    int xi, yi, intWidth = (w + 7) / 8;
    for (yi = 0; yi < h; yi++)
    {
        for (xi = 0; xi < w; xi++)
        {
            if (pgm_read_byte(bitmap + yi * intWidth + xi / 8) & (128 >> (xi & 7)))
            {
                Disp.drawPixel(x + xi, y + yi);
            } else if (color != 2)
            {
                Disp.setDrawColor(0);
                Disp.drawPixel(x + xi, y + yi);
                Disp.setDrawColor(color);
            }
        }
    }
}
