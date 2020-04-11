// 0ms, 100.00%; 2.3MB, 100.00%
func merge(nums1 []int, m int, nums2 []int, n int) {
	i := len(nums1) - 1
	m, n = m-1, n-1
	for m > -1 && n > -1 {
		if nums1[m] > nums2[n] {
			nums1[i] = nums1[m]
			i, m = i-1, m-1
		} else {
			nums1[i] = nums2[n]
			i, n = i-1, n-1
		}
	}
	for n > -1 {
		nums1[i] = nums2[n]
		i, n = i-1, n-1
	}
}
