void reverse(char *s , int l , int r)
{
    while(l < r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}
char* reverseWords(char* s) {
    int left = 0;
    int size = strlen(s);
    reverse(s,0,size-1);
    int i = 0;
    int j = 0;
    while(i < size && s[i] == ' ') i++;
    while(i < size)
    {
        s[j++] = s[i];
        if(s[i] == ' ')
        {
            reverse(s,left,j-1);
            while(i < size && s[i] == ' ')
            {
                i++;
            }
            left = j;
            continue;
        }
        i++;
    }
    // reverse(s,left,j-1);
    printf("%s",s);
    return s;
}
