class Solution {
    public String frequencySort(String s) {

        //check the String
        if(s.isEmpty() || (null == s))
        {
            return s;
        }

        //build the hashmap
        Map<Character, Integer> hmap = new HashMap<>();
        char[] chArr = s.toCharArray();
        for(char c : chArr)
        {
            hmap.put(c, hmap.getOrDefault(c, 0) + 1);
        }

        //bucket sort for the char set
        List<List<Character>> buckets = new ArrayList<>();
        int maxfreq = Collections.max(hmap.values());
        for(int i = 0; i <= maxfreq; ++i)
        {
            buckets.add(new ArrayList<Character>());
        }
        for(char c : hmap.keySet())
        {
            int freq = hmap.get(c);
            buckets.get(freq).add(c);
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = buckets.size() - 1; i >= 1; --i)
        {
            for(char c : buckets.get(i))
            {
                for(int j = 0; j < i; ++j)
                {
                    sb.append(c);
                }
            }
        }

        return sb.toString();
    }
}
