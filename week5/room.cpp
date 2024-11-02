//Leetcode: https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures_0(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++){ // n times
            for(int j = i + 1; j < temperatures.size(); j++){ // n - i - 1
                if(temperatures[j] > temperatures[i]){
                    result[i] = j - i;
                    break;
                }
            }
        } 
        // Running time =  O(n^2)
        // More careful analyis:
        // T(n) = (n - 1 + n - 2 + n - 3 ...+ 3 + 2 + 1 ) * c
        //      = (n-1)* n / 2 = n^2/2 - n/2
        // T(n) = O(n^2) (worst case)
        return result;     
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> days; 
        days.push(temperatures.size() - 1);
        for (int i = temperatures.size() - 2; i >=0 ; i--){  // (n -1)
            while(!days.empty() && 
                temperatures[i] >= temperatures[days.top()]){
                    days.pop(); // O(N) total over the entire program.
                                // Every value is pushed at most once,
                                // so it can only popped at most time
                                // We have n temperatures, total number of pops is O(N)
            } 
            if(!days.empty()){ // O(1)
                result[i] = days.top() - i;
            }
            days.push(i); // O(1)
        }
        return result;   
        // Overall T(n) = O(1) + O(n) (while loop total) + (n-1) * (O(1) -- rest of code in the for loop)
        //  = O(n) + O(n)
        // = O(n)
    }

        
};