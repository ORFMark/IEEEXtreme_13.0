// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
	static protected class Tree {
		protected Node root;

		// node class for use with the tree, contains the pointers and stuff
		protected class Node {
			protected int data;
			protected Node left;
			protected Node right;
			// Added variables used to print tree
			protected int depth;
			protected int leftOffset;

			protected Node(int data) {
				this.data = data;
				left = null;
				right = null;
				depth = 0;
				leftOffset = 0;
				
			}
			protected void display(Node myNode) {
			    System.out.println(myNode.data);
			}
		}

		// basic constructor
		public Tree() {
			root = null;
		}

		// deletes the tree
		public void clear() {
			root = null;
		}

		// deals with adding nodes to the tree. duplicates are allowed and go to the
		// right
		public int insert(int value) {
			Node newNode = new Node(value);
			int depth = 1;
			if (root == null) {
				root = newNode;
				return depth;
			} else {
				Node current = root;
				while (true) {
				    depth++;
					if (value < current.data) {
						// value being inserted is lower than current
						if (current.left != null) {
							current = current.left;
						} else {
							current.left = newNode;
							return depth;
						}
					} else {
						// value being inserted is higher (or same)
						if (current.right != null) {
							current = current.right;
						} else {
							current.right = newNode;
							return depth;
						}
					}
				}
			}
		}

		// publicly veiwable display (not recursive)
		public void display() {
			if (root != null) {
				display(root);
			}
			System.out.println();
		}

		private void display(Node node) {
			// in order traversal: display value between left and right
			if (node.left != null) {
				display(node.left);
			}
			System.out.print(Integer.toString(node.data) + " ");
			if (node.right != null) {
				display(node.right);
			}
		}
		
		public int getDepth() {
			if (root == null) {
				return -1;
			}
			else {
				return getDepth(root, 0);
			}
		}

		private int getDepth(Node current, int currentDepth) {
			int leftDepth = 0;
			int rightDepth = 0;
			if (current.right == null && current.left == null) {
				return currentDepth;
			}
			else {
				if(current.left != null) {
					leftDepth = getDepth(current.left, currentDepth+1);
				}
				if (current.right != null) {
					rightDepth = getDepth(current.right, currentDepth+1);
				}
				if (rightDepth < leftDepth) {
					return leftDepth;
				}
				else {
					return rightDepth;
				}
			}
		}
	}
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
	public static void main (String[] args) throws java.lang.Exception {
		FastReader in = new FastReader();
		Tree myTree = new Tree();
		int nodes = in.nextInt();
		for(int i = 0; i < nodes; i++) {
		    System.out.print(myTree.insert(in.nextInt()));
		    System.out.print(" ");
		}
		//myTree.display();
	}
}