/*
   Demetra Drizis
   Project 1
   09/24/19
*/
using namespace std; 

template <typename Comparable>
int ComparatorWithRead<Comparable> :: getDiff (const Comparable & lhs, const Comparable & rhs) const
{
	if (lhs < rhs)
	    return rhs - lhs;	
	else 
	    return lhs - rhs;
}

template <typename Comparable>
int findDiff (const Comparable & a, const Comparable & b)
{
	if (a < b)
	  return b - a;
	else 
	   return a - b;
}

template <typename Comparable, typename Comparator>
int findDiff (const Comparable & a, const Comparable & b, Comparator cmp)
{
	return cmp.getDiff(a, b);

}

template <typename T> 
int maxSubRange_Cubic (const NSequence <T> & a, const T & ref, const int range, int * start)
{
     T temprange{range};
     T temp_obj {0}; 
     int index, last, maxelements = 0;
     int lb = ref - temprange;
     int upperbound;
	if(ref < temprange)
		upperbound = (range - findDiff(ref, temprange)) + range;
	else 
		upperbound = (range + findDiff(ref, temprange)) + range; 
     for (int i = 0; i < a.getSize(); i++)
     {
        for (int j = i; j < a.getSize(); j++)
        {
	    int elements = 0;
	    for (int k = i; k <= j; k++)
            {
 		if(lb <= (a[k]-temp_obj)  && upperbound >= (a[k] - temp_obj))  
		{   
			elements++;
			if(elements > maxelements)
			{
				index = i;
				last = j;
				maxelements = elements; 
			}
		}
		else
		  break; 
	     }		
	}
   }
	*start = index;
	return (last-index) + 1;
}

template <typename T>
int maxSubRange_Quad(const NSequence <T> & a, const T & ref, const int range, int * start)
{
	T temprange{range};
     	T temp_obj {0};
	int index, last, maxelements = 0; 
	int lb = ref - temprange;
        int upperbound;

	if(ref < temprange)
                upperbound = (range - findDiff(ref, temprange)) + range;
        else
                upperbound = (range + findDiff(ref, temprange)) + range;


	for (int i = 0; i < a.getSize(); i++)
	{
		int elements = 0; 

	    for (int j = i; i < a.getSize(); j++)
	    {
		if(lb <= (a[j]-temp_obj)  && upperbound >= (a[j] - temp_obj))
                {
		    elements++; 
                    if (elements > maxelements)
                    {
                        index = i;
                        last = j;
                        maxelements = elements;
                    }
                }
                else
                  break;
	    }
	}

	*start = index;
	return (last - index) + 1;
}

template <typename T>
int maxSubRange_Linear(const NSequence <T> & a, const T & ref, const int range, int * start)
{
	T temprange{range};
        T temp_obj {0};
	int tempi = 0;
	int index, last, maxelements = 0; 
	int lb = ref - temprange;
        int upperbound;
	int elements = 0;

        if(ref < temprange)
                upperbound = (range - findDiff(ref, temprange)) + range;
        else
                upperbound = (range + findDiff(ref, temprange)) + range;

	for (int i = 0; i < a.getSize(); i++)
	{

	    if(lb <= (a[i]-temp_obj)  && upperbound >= (a[i] - temp_obj))
            {
		    elements++;
                    if (elements > maxelements)
                    {
                        index = tempi;
                        last = i;
                        maxelements = elements;
                    }
             }
             else
	     {
		   elements = 0;
		   tempi = i + 1;
	     }
	}

	*start = index;
	return (last - index) + 1; 
}

template <typename T>
int maxSubRange_Log(const NSequence <T> & a, const T & ref, const int range, int * start)
{
	return maxLog(a, ref, range, start, 0, a.getSize()); 
}

template <typename T>
int maxLog(const NSequence <T> & a, const T & ref, const int range, int * start, int begin, int end)
{
   int center = (begin + end) / 2; 
   int start_left, start_right, start_cross = 0; 

   if (begin == end) 
   {
	   return 1;
	   *start = end;
   }

   int left = maxLog(a, ref, range, & start_left, begin, center);
   int right = maxLog(a, ref, range, & start_right, center + 1, end);
   int middle = cross(a, ref, range, & start_cross, begin, end, center);
 
    if (left >= right && left >= middle)
    {
	*start = start_left;
	return left;
    }    
    else if (right >= left && right >= middle)
    {
	*start = start_right;
	return right;
    }
    else if (middle >= left && middle >= right)
    {	
       *start = start_cross;
       return middle;
    }
}

template <typename T>
int cross(const NSequence <T> & a, const T & ref, const int range, int * start, int begin, int end, int m)
{
   int left = 0;
   int right = 0;
   *start = 0; 
  
   for (int i = m; i <= begin; i--)
   {
      if (findDiff(a[i], ref) <= range)
      {
	left++;
      }
      else
      {
         *start = i+1;
         break; 
      }

   }
   for (int i = m+1; i <= end; i++)
   {
     if (findDiff(a[i], ref) <= range)
     {  
	 right++;
     }	
     else
     {
       break;
     } 
   }

  	return (left + right); 
}
