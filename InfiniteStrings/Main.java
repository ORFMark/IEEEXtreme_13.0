// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
	/* Function: string_build_recursive
	 * Purpose:  builds a lexicographical string recursively with depth "size"
	 * Returns:  the number of characters included in the string
	 */
	public static void string_build_recursive(StringBuilder buffer,
			long high, String pref, Integer size, long target) {
		//int charactersAdded = 0;
		for (int i = 1; i <= high; i++) {
			if (size == 1) {
				buffer.append(pref + (char)(i + 96));
				//charactersAdded += pref.length() + 1;
				
				// check if we can leave recursive loop
				if (buffer.toString().length() > target)
					return;
			} else {
				string_build_recursive(buffer, high,
						pref + (char)(i + 96), size - 1, target);
				if (buffer.toString().length() > target)
					return;
			}
		}
		return; // void
	}
	
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner in = new Scanner(System.in); // init scanner
	    int T = in.nextInt(); // number of test cases
	    for (int __ = 0; __ < T; __++) {
	        long B = in.nextLong(); // the number of characters to use of the alphabet
	        long X = in.nextLong(); // the index for a character from the built string
	        
	        // for building B's lexicographical ordered string
		    StringBuilder myStringBuilder = new StringBuilder(0);
		    
		    // maximum loop time is 26 for 26 letters
		    for (int i = 1; i <= 26; i++) {
		    	// i* B ^ i from X. If this is positive, continue.
		    	if (X - i*Math.pow(B,i) >= 0) {
		    		X -= i*Math.pow(B,i);
		    		continue;
		    	}
		    	
		    	if (X > 1000000) {
		    		// attempt this algorithm
		    		long maxModulo = 1;
		    		int n = 0;
		    		for (n = 0; n < i; n++) {
		    			if (X > n*Math.pow(B,n)) {
		    				maxModulo = (long)(n*Math.pow(B, n));
		    			} else {
		    				break;
		    			}
		    		}
		    		X %= maxModulo;
		    		//i -= n;
	    		}
	    
		    	// append integers to myStringBuilder until we have reached index X
		    	string_build_recursive(myStringBuilder, B, "", i, X);
		    	
		    	if (myStringBuilder.toString().length() > X) {
		    		// output the result
		    		System.out.println(myStringBuilder.toString().charAt((int)X));
		    		break;
		    	}
		    }
	        
	    }
	}
}