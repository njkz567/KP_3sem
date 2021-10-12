#ifndef FUN_H
#define FUN_H
extern "C"
{
    void print (int *A, const int amount);

    int my_abs (const int a);

    int getRandomNumber(int min, int max);

    void full (int *A, const int amount);

    void change_sign ();
}
#endif // FUN_H
