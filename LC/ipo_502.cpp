class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projs;
        int num = capital.size(); // can also choose from profits.size()

        for(int i = 0; i < num; ++i)
        {
            /*add the list of unavailable projects to vector
            with capital+profits combo for each project*/
            projs.emplace_back(capital[i], profits[i]);
        }

        /*now, sort the projects based on ascending order of capital
        - so as to choose best profitable project within capital w*/
        sort(projs.begin(), projs.end());

        //max heap
        priority_queue<int> pq;

        /*init available project for selection to first one in projs.
        if it is still > w, then we can't choose any projects*/
        int curr = 0;
        if(curr < num && projs[curr].first > w)
            return w;

        while(k--)
        {
            //add the available projects to the max heap
            while((curr < num) && (projs[curr].first <= w))
            {
                pq.push(projs[curr].second);
                //next project for selection
                ++curr;
            }
            /*can't proceed if there are no more projects in queue*/
            if(pq.empty()) break;
            /* add the best profitable project's profit to total 
            from max heap. */
            w = w + pq.top(); 
            pq.pop(); // completed the best profitable project
        }
        return w;
    }
};
