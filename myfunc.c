double find_rectangle_perymetr(double width, double length)
{
    if(width < 0 || length < 0)
        return 0;
    return (2 * (width + length));
}

int abs_int(int x)
{
    return (x < 0) ? -x : x;
}

int sqr_int(double x)
{
    return (int )(x * x);
}