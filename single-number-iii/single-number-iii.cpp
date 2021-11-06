class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_val = 0;
        for(int i=0;i<n;i++)
            xor_val ^= nums[i];
        int pos = 0;
        // cout<<xor_val<<"\n";
        for(int i=0;i<32;i++)
        {
            if((xor_val>>i) & 1 == 1)
            {
                pos = i;
                break;
            }
        }
        // cout<<pos<<"\n";
        int num1 = 0,num2 = 0;
        // int temp = 1<<pos;
        // cout<<temp<<"\n";
        for(int i=0;i<n;i++)
        {
            int val = (nums[i]>>pos) & 1;
            // cout<<val<<" ";
            if(val == 1)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        return {num1,num2};
    }
};

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         int xor_val = 0;
//         for(int i=0;i<n;i++)
//         {
//             xor_val ^= nums[i];
//         }
//         cout<<xor_val<<"\n";
//         int shift = 0;
//         // cout<<xor_val;
//         for(int i=0;i<32;i++)
//         {
//             if(xor_val>>i & 1 == 1)
//             {
//                 shift = i;
//                 break;
//             }
//         }
//         cout<<shift<<"\n";
//         int num1 = 0,num2 = 0;
//         // cout<<shift;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]>>shift & 1 == 1)
//             {
//                 num1 ^= nums[i];
//             }
//             else
//                 num2 ^= nums[i];
//         }
//         return {min(num1,num2),max(num1,num2)};
//     }
// };