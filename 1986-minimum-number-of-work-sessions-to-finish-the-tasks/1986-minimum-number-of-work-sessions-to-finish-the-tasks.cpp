class Solution {
    int min_sessions = INT_MAX;
    vector<int> sessions;
    
public:
    int min(int a, int b) {
        if(a > b) {
            return b;
        } else {
            return a;
        }
    }
    
    void solve(vector<int>& tasks, int sessionTime, int idx) {
        if(sessions.size() > min_sessions) return;
        
        if(idx == tasks.size()) {
            min_sessions = min(min_sessions, sessions.size());
            return;
        }
        
        for(int i = 0; i < sessions.size(); i++) {
            if(sessions[i] + tasks[idx] <= sessionTime) {
                sessions[i] += tasks[idx];
                solve(tasks, sessionTime, idx + 1);
                sessions[i] -= tasks[idx];
            }
        }
        
        sessions.push_back(tasks[idx]);
        solve(tasks, sessionTime, idx + 1);
        sessions.pop_back();
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        solve(tasks, sessionTime, 0);
        return min_sessions;
    }
};