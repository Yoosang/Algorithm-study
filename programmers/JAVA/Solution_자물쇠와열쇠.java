package programmers;

public class Solution_切弘取人伸取 {
	public boolean solution(int[][] key, int[][] lock) {
        int[][] map = setMap(lock, key.length - 1);
        int[][] temp;
        
        for(int i = 0; i < 4; i++) {
        	key= rotate(key);
        	for(int j = 0; j < map.length - (key.length - 1); j++) {
            	for(int k = 0; k < map.length - (key.length - 1); k++) {
            		temp = setKey(map, key, j, k);
            		if(unlock(key.length, map.length, temp)) {
            			return true;
            		}
            	}
            }
        	
        }
        return false;
    }
	
	public boolean unlock(int keySize, int mapSize, int[][] map) {
		for(int i = keySize - 1; i < mapSize - keySize + 1; i++) {
			for(int j = keySize - 1; j < mapSize - keySize + 1; j++) {
				if(map[i][j] != 1) {
					return false;
				}
			}
		}
		return true;
	}
	
	public int[][] setKey(int[][] map, int[][] key, int r, int c) {
		int keySize = key.length;
		int mapSize = map.length; 
		int[][] ret = new int[mapSize][mapSize];
		
		for(int i = 0; i<mapSize; i++) {
			for(int j = 0; j<mapSize; j++) {
				ret[i][j] = map[i][j];
			}
		}
		
		for(int i = r; i < r + keySize; i++) {
			for(int j = c; j < c + keySize; j++) {
				ret[i][j] += key[i - r][j - c];
			}
		}
		return ret;
	}
	
	public int[][] rotate(int[][] arr){
		int size = arr.length;
		int[][] ret = new int[size][size];
		
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				ret[j][(size -1) - i] = arr[i][j];
			}
		}
		return ret;
	}
	
	public int[][] setMap(int[][] arr, int size) {
		int[][] ret = new int[arr.length + (size * 2)][arr.length + (size * 2)];
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j< arr.length; j++) {
				ret[i + size][j + size] = arr[i][j];
			}
		}
		return ret;
	}
	
}
