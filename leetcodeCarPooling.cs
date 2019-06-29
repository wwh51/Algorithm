public class Solution
    {
        private int FindIndexGreat(List<int[]> passangers, int target)
        {
            int low = 0;
            int high = passangers.Count - 1;
            int mid = 0;
            while (low <= high)
            {
                mid = low + ((high - low) >> 1);
                if (target < passangers[mid][2])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }

            }
            return low <= passangers.Count - 1 ? low : -1;
        }
        public bool CarPooling(int[][] trips, int capacity)
        {
            if (trips.Length <= 1)
                return trips[0][0] <= capacity;

            trips = trips.OrderBy(c => c[1]).ToArray();
            int currentNum = trips[0][0];
            var passangers = new List<int[]>();
            passangers.Add(trips[0]);

            for (int i = 1; i < trips.Length; ++i)
            {
                var currPos = trips[i][1];
                int toBeRemoved = FindIndexGreat(passangers, currPos);
                if (toBeRemoved < 0)
                    toBeRemoved = passangers.Count;
                for (int j = 0; j < toBeRemoved; ++j)
                {
                    currentNum -= passangers[j][0];
                }
                if (toBeRemoved > 0)
                    passangers.RemoveRange(0, toBeRemoved);
                currentNum += trips[i][0];
                if (currentNum > capacity)
                    return false;

                int insertPos = FindIndexGreat(passangers, trips[i][2]);
                if (insertPos < 0)
                    passangers.Add(trips[i]);
                else
                {
                    passangers.Insert(insertPos, trips[i]);
                }
            }
            return true;
        }
    } 
