#ifndef COLORPIXEL_H
#define COLORPIXEL_H

class ColorPixel{
private:
    int redValue;
    int blueValue;
    int greenValue;
    unsigned char binRed;
    unsigned char binGreen;
    unsigned char binBlue;

public:
    ColorPixel(int redValue, int blueValue, int greenValue);
    ColorPixel(unsigned char binRed,unsigned char binGreen,unsigned char binBlue);
    ColorPixel();
    ~ColorPixel();
    int getRedValue();
    int getBlueValue();
    int getGreenValue();
    unsigned char getBinRed();
    unsigned char getBinGreen();
    unsigned char getBinBlue();

};

#endif // COLORPIXEL_H
