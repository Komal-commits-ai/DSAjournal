#include <iostream>
#include <vector>
#include <queue>

class Tree
{
    int* tree;
    int size;
    int p; // Index of the last element

public:
    Tree()
    {
        size = 100;
        tree = new int[size];
        p = -1;
    }

    void insertNode(int value)
    {
        if (p == size - 1)
        {
            int* t = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                t[i] = tree[i];
            }
            size = size * 2;
            delete[] tree;
            tree = t;
        }
        p++;
        tree[p] = value;
    }

    int searchNode(int value)
    {
        for (int i = 0; i <= p; i++)
        {
            if (tree[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    void deleteNode(int value)
    {
        int ind = searchNode(value);
        if (ind == -1)
        {
            std::cout << "Node not found.\n";
            return;
        }
        tree[ind] = tree[p];
        p--;
    }

    void inorderTraversal(int i)
    {
        if (i > p || tree[i] == -1) return;

        if ((2 * i) + 1 <= p && tree[(2 * i) + 1] != -1)
        {
            inorderTraversal((2  * i) + 1);
        }

        std::cout << tree[i] << ' ';

        if ((2 * i) + 2 <= p && tree[(2 * i) + 2] != -1)
        {
            inorderTraversal((2 * i) + 2);
        }
    }

    void preorderTraversal(int i)
    {
        if (i > p || tree[i] == -1) return;

        std::cout << tree[i] << ' ';

        if ((2 * i) + 1 <= p && tree[(2 * i) + 1] != -1)
        {
            preorderTraversal((2 * i) + 1);
        }

        if ((2 * i) + 2 <= p && tree[(2 * i) + 2] != -1)
        {
            preorderTraversal((2 * i) + 2);
        }
    }

    void postorderTraversal(int i)
    {
        if (i > p || tree[i] == -1) return;

        if ((2 * i) + 1 <= p && tree[(2 * i) + 1] != -1)
        {
            postorderTraversal((2 * i) + 1);
        }

        if ((2 * i) + 2 <= p && tree[(2 * i) + 2] != -1)
        {
            postorderTraversal((2 * i) + 2);
        }

        std::cout << tree[i] << ' ';
    }

    void levelOrderTraversal()
    {
        if (p == -1) return;

        std::queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i <= p && tree[i] != -1)
            {
                std::cout << tree[i] << ' ';
                if ((2 * i) + 1 <= p) q.push((2 * i) + 1);
                if ((2 * i) + 2 <= p) q.push((2 * i) + 2);
            }
        }
    }

    int height(int i)
    {
        if (i > p || tree[i] == -1) return 0;

        int leftHeight = (2 * i) + 1 <= p ? height((2 * i) + 1) : 0;
        int rightHeight = (2 * i) + 2 <= p ? height((2 * i) + 2) : 0;

        return 1 + std::max(leftHeight, rightHeight);
    }

    void display()
    {
        for (int i = 0; i <= p; i++)
        {
            if (tree[i] != -1)
            {
                std::cout << tree[i] << ',';
            }
        }
        std::cout << '\n';
    }

    ~Tree()
    {
        delete[] tree;
    }
};

int main()
{
    Tree tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);

    std::cout << "In-order Traversal: ";
    tree.inorderTraversal(0);
    std::cout << "\nPre-order Traversal: ";
    tree.preorderTraversal(0);
    std::cout << "\nPost-order Traversal: ";
    tree.postorderTraversal(0);
    std::cout << "\nLevel-order Traversal: ";
    tree.levelOrderTraversal();

    std::cout << "\nHeight of tree: " << tree.height(0);

    std::cout << "\nDisplay Tree: ";
    tree.display();

    return 0;
}
