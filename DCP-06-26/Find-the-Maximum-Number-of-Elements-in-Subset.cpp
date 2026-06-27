1class Solution
2{
3public:
4    int maximumLength(vector<int>& nums)
5    {
6        unordered_map<long long, int> freq;
7
8        // Count frequency
9        for (int i = 0; i < nums.size(); i++)
10        {
11            freq[nums[i]]++;
12        }
13
14        int ans = 1;
15
16        // Handle 1 separately
17        if (freq.find(1) != freq.end())
18        {
19            ans = freq[1];
20
21            if (ans % 2 == 0)
22            {
23                ans--;
24            }
25        }
26
27        unordered_map<long long, int>::iterator it;
28
29        for (it = freq.begin(); it != freq.end(); it++)
30        {
31            long long num = it->first;
32
33            if (num == 1)
34                continue;
35
36            long long current = num;
37            int length = 0;
38
39            while (true)
40            {
41                unordered_map<long long, int>::iterator temp = freq.find(current);
42
43                if (temp == freq.end() || temp->second < 2)
44                    break;
45
46                length += 2;
47                current = current * current;
48            }
49
50            unordered_map<long long, int>::iterator temp = freq.find(current);
51
52            if (temp != freq.end())
53            {
54                length++;
55            }
56            else
57            {
58                length--;
59            }
60
61            if (length > ans)
62            {
63                ans = length;
64            }
65        }
66
67        return ans;
68    }
69};