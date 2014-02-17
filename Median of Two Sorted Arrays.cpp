/*
Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
		int k=m+n;
		if(k&0x1)
		{
			return findKth(A,m,B,n,k/2+1); 
		}
		else
		{
			return (findKth(A,m,B,n,k/2+1)+findKth(A,m,B,n,k/2))/2;
		}
	}
	double findKth(int A[],int m,int B[],int n,int k)
	{
		if(m>n)
		{
			return findKth(B,n,A,m,k);
		}
			if(m==0)
		{
			return B[k-1];
		}
		if(k<=1)
		{
			return min(A[0],B[0]);
		}

		int tempa=min(k/2,m);int tempb=k-tempa;

		if(A[tempa-1]>B[tempb-1])
		{
			return findKth(A,m,B+tempb,n-tempb,k-tempb);
		}
		else
		{
			if(A[tempa-1]<B[tempb-1])
			{
				return findKth(A+tempa,m-tempa,B,n,k-tempa);
			}
			else
			{
				return A[tempa-1];
			}
		}

	}
};
