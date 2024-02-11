/ MAX OF SCORES
int find_max(int score1, int score2, int score3)
{
    int max = score1;

    if (score2 > max)
    {
        max = score2;
    }
    if (score3 > max)
    {
        max = score3;
    }

    return max;
}
