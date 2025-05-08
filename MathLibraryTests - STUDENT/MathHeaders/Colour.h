#pragma once

namespace MathClasses
{
    using Byte = unsigned char;
    struct Colour
    {
        unsigned int colour;

        Colour() {
            colour = 0b0;
        };

        Colour(Byte red, Byte green, Byte blue, Byte alpha) {
            colour = 0b0;
            colour |= static_cast<unsigned int>(red << 24);
            colour |= static_cast<unsigned int>(green << 16);
            colour |= static_cast<unsigned int>(blue << 8);

            colour |= static_cast<unsigned int>(alpha);
        }

        Byte GetRed() const { 
            return static_cast<Byte>((colour >> 24) & (0b11111111)); 
        }
        Byte GetGreen() const {
            return static_cast<Byte>((colour >> 16) & (0b11111111));
        }
        Byte GetBlue() const {
            return static_cast<Byte>((colour >> 8) & (0b11111111));
        }
        Byte GetAlpha() const {
            return static_cast<Byte>((colour & 0b11111111));
        }

        void SetRed(Byte red) {
            colour &= 0b00000000111111111111111111111111;
            // Implicit conversion to int, then static cast to unsigned int.
            colour |= static_cast<unsigned int>(red << 24);
        }
        void SetGreen(Byte green) {
            colour &= 0b11111111000000001111111111111111;
            colour |= static_cast<unsigned int>(green << 16);
        }
        void SetBlue(Byte blue) {
            colour &= 0b11111111111111110000000011111111;
            colour |= static_cast<unsigned int>(blue << 8);
        }
        void SetAlpha(Byte alpha) {
            colour &= 0b11111111111111111111111100000000;
            colour |= static_cast<unsigned int>(alpha);
        }

        bool operator==(const Colour& o) const {
            if ((colour ^ o.colour) == 0) {
                return true;
            }
            else {
                return false;
            }
        }

    };
}