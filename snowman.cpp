#include <iostream>
#include <string>
#include <stdexcept>
#include "snowman.hpp"

namespace ariel
{
        std::string snowman(int num)
        {
                // First let's check if the number is positive.
                if (num <= 0)
                {
                        throw std::out_of_range{"The number must be positive!\n"};
                }
                // ******************
                // ***** consts *****
                // ******************
                const int zero = 0;
                const int one = 1;
                const int two = 2;
                const int three = 3;
                const int four = 4;
                const int five = 5;
                const int six = 6;
                const int seven = 7;
                const int eight = 8;
                const int ten = 10;
                // *******************
                // ***** program *****
                // *******************
                // Now we are going to check the length of the number, it must be equals to eight.
                string temp = to_string(num);
                string ans;
                if (temp.length() != eight)
                {
                        throw std::out_of_range{"The length of the number must be 8!\n"};
                }
                bool ex = false;
                // Assign each number to the right value.
                int h = zero; // |head|
                int n = zero; // |nose|
                int l = zero; // |left eye|
                int r = zero; // |right eye|
                int x = zero; // |left arm|
                int y = zero; // |right arm|
                int t = zero; // |torso|
                int b = zero; // |bottom|
                for (int i = zero; i < eight; ++i)
                {
                        switch (i)
                        {
                        case zero:
                                b = num % ten;
                                if (b <= zero || four < b)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case one:
                                t = num % ten;
                                if (t <= zero || four < t)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case two:
                                y = num % ten;
                                if (y <= zero || four < y)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case three:
                                x = num % ten;
                                if (x <= zero || four < x)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case four:
                                r = num % ten;
                                if (r <= zero || four < r)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case five:
                                l = num % ten;
                                if (l <= zero || four < l)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case six:
                                n = num % ten;
                                if (n <= zero || four < n)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        case seven:
                                h = num % ten;
                                if (h <= zero || four < h)
                                {
                                        ex = true;
                                        break;
                                }
                                num = num / ten;
                                break;
                        default:
                                break;
                        }
                        if (ex)
                        {
                                break;
                        }
                }
                if (ex)
                {
                        throw std::out_of_range{"One of the numbers is not between 1 and 4.\n"};
                }
                // Rrawing the face and torso, that way it will be much easier to build the snowman, so let's start with the nose.
                switch (n)
                {
                case one:
                        ans = ans + ",";
                        break;
                case two:
                        ans = ans + ".";
                        break;
                case three:
                        ans = ans + "_";
                        break;
                case four:
                        ans = ans + " ";
                        break;
                default:
                        break;
                }
                // The next thing to do is to draw the left eye
                switch (l)
                {
                case one:
                        ans = "(." + ans;
                        break;
                case two:
                        ans = "(o" + ans;
                        break;
                case three:
                        ans = "(O" + ans;
                        break;
                case four:
                        ans = "(-" + ans;
                        break;
                default:
                        break;
                }
                // Next drawing the right eye
                switch (r)
                {
                case one:
                        ans = ans + ".)";
                        break;
                case two:
                        ans = ans + "o)";
                        break;
                case three:
                        ans = ans + "O)";
                        break;
                case four:
                        ans = ans + "-)";
                        break;
                default:
                        break;
                }
                // At this level answer will be like: (LNR) -> that supposed to be the head lol
                // Maybe the next thing will make the most of you angry, but I'm gonna check the left hand and the right hand TWICE.
                // The reason is - To check where to place the hands of the snowman.
                // So let's begin with the left hand with the upper position.
                if (x == two)
                {
                        ans = "\\" + ans;
                }
                else
                {
                        ans = " " + ans;
                }
                // Drawing the right hand (The upper position)
                if (y == two)
                {
                        ans = ans + "/\n";
                }
                else
                {
                        ans = ans + " \n";
                }
                // After that the snowman should look like this: X(LNR)Y,
                // So let's draw the lower part of the body, starting with the left hand.
                switch (x)
                {
                case one:
                        ans = ans + "<";
                        break;
                case three:
                        ans = ans + "/";
                        break;
                default:
                        ans = ans + " ";
                        break;
                }
                // Drawing the torso
                switch (t)
                {
                case one:
                        ans = ans + "( : )";
                        break;
                case two:
                        ans = ans + "(] [)";
                        break;
                case three:
                        ans = ans + "(> <)";
                        break;
                case four:
                        ans = ans + "(   )";
                        break;
                default:
                        break;
                }
                // Drawing the lower part of right hand.
                switch (y)
                {
                case one:
                        ans = ans + ">\n";
                        break;
                case three:
                        ans = ans + "\\\n";
                        break;
                default:
                        ans = ans + " \n";
                        break;
                }
                // And now the snowman looks like this:  X(LNR)Y
                //                                       X(TTT)Y
                // when X is the left arm and Y is the right arm.
                // So let's draw the base and then the hat
                switch (b)
                {
                case one:
                        ans = ans + " ( : )";
                        break;
                case two:
                        ans = ans + " (" + '"' + " " + '"' + ")";
                        break;
                case three:
                        ans = ans + " (___)";
                        break;
                case four:
                        ans = ans + " (   )";
                        break;
                default:
                        break;
                }
                // Drawing the hat
                switch (h)
                {
                case one:
                        ans = "      \n _===_\n" + ans;
                        break;
                case two:
                        ans = "  ___ \n .....\n" + ans;
                        break;
                case three:
                        ans = "   _  \n  /_\\ \n" + ans;
                        break;
                case four:
                        ans = "  ___ \n (_*_)\n" + ans;
                        break;
                default:
                        break;
                }
                return ans;
        }
}
