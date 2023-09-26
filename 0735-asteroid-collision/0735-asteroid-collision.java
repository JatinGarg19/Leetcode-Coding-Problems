class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        
        for(int asteroid: asteroids) {
            // If asteroid is + sign, simply push onto stack since it cant collide.
            if(asteroid > 0) {
                st.push(asteroid);
            } else {  // If the asteroid is with - sign, there could be couple of cases.
                while(!st.isEmpty() && st.peek() > 0 && st.peek() < Math.abs(asteroid)) {
                    st.pop();
                }
                if(st.isEmpty() || st.peek() < 0) {
                    st.push(asteroid);
                } else if(asteroid + st.peek() == 0) {
                    st.pop();
                }
            }
        }
        
        int[] res = new int[st.size()];
        for(int i = res.length - 1; i >= 0; i--) {
            res[i] = st.pop();
        }
        
        return res;
    }
}