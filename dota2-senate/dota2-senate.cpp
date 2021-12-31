class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int ban_r = 0,ban_d = 0;
        set<char> s;
        vector<int> ban(n,0);
        while(s.size()!=1)
        {
            s.clear();
            for(int i=0;i<n;i++)
            {
                if(ban[i] == 1)
                    continue;
                else
                {
                    if(senate[i] == 'R')
                    {
                        if(ban_r>0)
                        {
                            ban_r -= 1;
                            ban[i] = 1;
                        }
                        else
                        {
                            ban_d += 1;
                            s.insert('R');
                        }
                    }
                    else
                    {
                        if(ban_d>0)
                        {
                            ban_d -= 1;
                            ban[i] = 1;
                        }
                        else
                        {
                            ban_r += 1;
                            s.insert('D');
                        }
                    }
                }
            }
        }
        if(*s.begin() == 'R')
            return "Radiant";
        return "Dire";
    }
};