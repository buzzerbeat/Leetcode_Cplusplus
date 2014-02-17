/*
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len=s.length();
        if(len==0)
        {
            return 0;
        }
        string sub;
        int max=0;
        int current=0;
        for(int i=0;i<len;i++)
        {
            sub.append(1,s.at(i));
            for(int j=0;j<sub.length();j++)
            {
                if(j==sub.length()-1)
                {
                     current++; 
                if(current>=max)
                {
                    max=current;
                }
                }
                else
                {
                if(sub.at(j)==s.at(i))
                {
                    if(current>=max)
                    {
                        max=current;
                    }
                    i=i-current;
                    current=0;
             
                    sub.erase(0,sub.length());
                    break;
                }
                }
            }
           
        }
        return max;
        
    }
};
