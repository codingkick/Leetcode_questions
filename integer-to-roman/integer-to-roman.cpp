class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mpp;
        mpp[1] = 'I';
        mpp[5] = 'V';
        mpp[10] = 'X';
        mpp[50] = 'L';
        mpp[100] = 'C';
        mpp[500] = 'D';
        mpp[1000] = 'M';
        mpp[4] = "IV";
        mpp[9] = "IX";
        mpp[40] = "XL";
        mpp[90] = "XC";
        mpp[400] = "CD";
        mpp[900] = "CM";
        string ans = "";
        int temp = (int)(num/1000);
        num = num%1000;
        while(temp--)
        {
            ans += mpp[1000];
        }
        temp = (int)(num/900);
        num = num%900;
        while(temp--)
        {
            ans += mpp[900];
        }
        temp = (int)(num/500);
        num = num%500;
        while(temp--)
        {
            ans += mpp[500];
        }
        temp = (int)(num/400);
        num = num%400;
        while(temp--)
        {
            ans += mpp[400];
        }
        temp = (int)(num/100);
        num = num%100;
        while(temp--)
        {
            ans += mpp[100];
        }
        temp = (int)(num/90);
        num = num%90;
        while(temp--)
        {
            ans += mpp[90];
        }
        temp = (int)(num/50);
        num = num%50;
        while(temp--)
        {
            ans += mpp[50];
        }
        temp = (int)(num/40);
        num = num%40;
        while(temp--)
        {
            ans += mpp[40];
        }
        temp = (int)(num/10);
        num = num%10;
        while(temp--)
        {
            ans += mpp[10];
        }
        temp = (int)(num/9);
        num = num%9;
        while(temp--)
        {
            ans += mpp[9];
        }
        temp = (int)(num/5);
        num = num%5;
        while(temp--)
        {
            ans += mpp[5];
        }
        temp = (int)(num/4);
        num = num%4;
        while(temp--)
        {
            ans += mpp[4];
        }
        temp = (int)(num/1);
        num = num%1;
        while(temp--)
        {
            ans += mpp[1];
        }
        return ans;
    }
};