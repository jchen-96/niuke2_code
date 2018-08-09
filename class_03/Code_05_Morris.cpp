// Morris 遍历，采用空间复杂度为O(1) 实现，不用任何栈空间

/**
 * 开始cur 指针指向头节点
 * 
 * 当cur 有左孩子 ，找到左子树的最右节点mostright
 *          mostright 的右指针为空，mostright->right=cur, cur=cur.left
 *          mostright 的右指针为==cur，mostright-ritht=null,cur=cur.right
 **/