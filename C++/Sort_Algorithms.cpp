/*
    排序算法：插入排序、冒泡排序、希尔排序、堆排序、归并排序、快速排序、桶排序

        插入排序：每来一个数，插入以有的排好序的列表里（排序号的列表是当前位置之前的列表）。
        冒泡排序：对数组的第0个数据到N-1个数据进行一次遍历，每次最大的一个数据就“沉”到数组第N-1个位置。
        希尔排序：
*/
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;

#include"MinHeap.h"
/*
	插入排序：
		每来一个数，插入以有的排好序的列表里（排序号的列表是当前位置之前的列表）。
		时间复杂度为：O(N^2 )；(显然每个数都要和前面排过序的数比较)
*/
void insertSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            int tmp = nums[i];
            size_t j = 0;
            for (j = i - 1; j >= 0, nums[j] > tmp; --j) {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = tmp;
        }
    }
    return;
}

/*
	冒泡排序：
		设数组长度为N：
			1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
			2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
			3．N=N-1，如果N不为0就重复前面二步，否则排序完成。

		时间复杂度：O(N^2 )；(同样：每个数都要和其他数比较)    
*/
void bubbleSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
    return;
}

/*
	希尔排序：
		希尔排序的实质就是分组插入排序，该方法又称缩小增量排序。

		基本思想：
			先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
			然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一
			次直接插入排序。
*/
void shellSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
        for (int i = 0; i < gap; ++i) {
            for (int j = i + gap; j < nums.size(); j += gap) {
                if (nums[j] < nums[j - gap]) {
                    int tmp = nums[j];
                    int k = 0;
                    for (k = j - gap; k >= 0 && nums[k] > tmp; k -= gap) {
                        nums[k + gap] = nums[k];
                    }
                    nums[k + gap] = tmp;
                }
            }
        }
    }
    return;
}

/*
	堆排序：
		主要是用二叉堆来进行排序。代码也就是实现堆。

		二叉堆的定义：
		二叉堆是完全二叉树或者是近似完全二叉树。
		二叉堆满足二个特性：
			1．父结点的键值总是大于或等于（小于或等于）任何一个子节点的键值。
			2．每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）。
		当父结点的键值总是大于或等于任何一个子节点的键值时为最大堆。当父结点的键值总是小于或等于任何一
		个子节点的键值时为最小堆。
*/
void heapSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    MinHeap<int> tmp;
    for (const auto& i : nums) {
        tmp.insert(i);
    }
    tmp.printf(nums, nums.size());
    return;
}

/*
	归并排序：
		该算法采用分治法，考虑将两个有序的数组进行归并。

		可以将A，B组各自再分成二组。依次类推，当分出来的小组只有一个数据时，可以认为这个小组组内已经
		达到了有序。
*/
// 将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergeArray(vector<int>& nums, vector<int>& tmp, int left, int center, int right) {
    int i = left, j = center + 1;
    int m = center, n = right;
    int k = 0;

    while (i <= m && j <= n) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }

	while (i <= m)
		tmp[k++] = nums[i++];

	while (j <= n)
		tmp[k++] = nums[j++];

	for (i = 0; i < k; i++)
		nums[left + i] = tmp[i];
    return;
}
void MSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = left + (right - left) / 2;
        MSort(nums, tmp, left, center);
        MSort(nums, tmp, center + 1, right);
        mergeArray(nums, tmp, left, center, right);
    }
    return;
}
void MergeSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    int n = nums.size();
    vector<int> tmp(n, 0);
    MSort(nums, tmp, 0, n - 1);
    return;
}

/*
	快速排序：
		划分交换排序，同样采用分治的策略。

		该方法的基本思想是：
			1．先从数列中取出一个数作为基准数。
			2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
			3．再对左右区间重复第二步，直到各区间只有一个数。
*/
void QSort(vector<int>& nums, int left, int right) {
    if (nums.empty()) {
        return;
    }

    int i = left, j = right, x = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= x) {
            --j;
        }
        swap(nums[i], nums[j]);
		while (i < j && nums[i] <= x)
			++i;
		swap(nums[i], nums[j]);
	}
	QSort(nums, left, i - 1);
	QSort(nums, i + 1, right);
}

void QuickSort(vector<int>& nums)
{
    if (nums.empty()) {
        return;
    }
    int n = nums.size();
	QSort(nums, 0, n - 1);
    return;
}
