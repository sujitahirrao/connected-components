# Connected-Components

Extraction of connected components from the images with PGM file format using Otsu's thresholding and BFS/DFS methods.

To run the code:
```
cd x64\Release\
```
```
ExtractConnectedComponents.exe <input.pgm> <threshold=50> <method=1>
```

Threshold is the size of the components below which all the connected components are blackened (removed). The default is 50. 
Method is either 1 for BFS or 2 for DFS. The default is 1.

Output image after Otsu-thresholding is stored in ```data/output```

The time complexities of BFS and DFS are ```O(V + E)``` each, where V is the number of nodes and E is the number of edges.
