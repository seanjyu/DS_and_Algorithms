"""
Binary Search Implementation in python
"""


def binary_search(sorted_list: list, search_val):
    '''
    Inputs: 
        sorted_list: Sorted List of values
        search_val: Value to be searched
    Output: 
        returns index of search value if in sorted_list, if not then False is returned
    '''
    n_list = len(sorted_list)
    left_pointer = 0
    right_pointer = n_list - 1
    
    while left_pointer <= right_pointer:
        mid_pointer = (left_pointer + right_pointer) // 2
        if sorted_list[mid_pointer] == search_val:
            return mid_pointer
        elif sorted_list[mid_pointer] < search_val:
            left_pointer = mid_pointer + 1
        elif sorted_list[mid_pointer] > search_val:
            right_pointer = mid_pointer - 1

    return False


if __name__ == "__main__":
    print(binary_search([1,2,3,4,5], 10))