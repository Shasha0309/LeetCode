<h2><a href="https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree">Burning Tree</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary tree and a&nbsp;<strong>node data</strong> called <strong>target</strong>. Find the minimum time required to burn the complete binary tree if the target is set on fire.&nbsp;It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.<br><strong>Note:</strong> The tree contains unique values.</span></p>
<p><strong><span style="font-size: 18px;">Examples :&nbsp;</span></strong></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">root[] = [1,2,3,4,5,N,6,N,N,7,8,N,9,N,N,N,N,N,10],  target = 8</span><strong style="font-size: 18px;"><br></strong><strong style="font-size: 18px;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/702131/Web/Other/blobid0_1733996113.jpg" width="349" height="290">  </strong></span>
<span style="font-size: 18px;"><strong>Output:</strong> 7</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> <span class="hljs-variable">root</span><span class="hljs-punctuation">[</span><span class="hljs-punctuation">]</span> <span class="hljs-operator">=</span> <span class="hljs-punctuation">[</span><span class="hljs-number">1</span><span class="hljs-operator">,</span> <span class="hljs-number">2</span><span class="hljs-operator">,</span> <span class="hljs-number">3</span><span class="hljs-operator">,</span> <span class="hljs-number">4</span><span class="hljs-operator">,</span> <span class="hljs-number">5</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-number">7</span><span class="hljs-operator">,</span> <span class="hljs-number">8</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-number">10</span><span class="hljs-punctuation">]</span><span class="hljs-operator">,</span> target = 10
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10</span>
<span style="font-size: 18px;"><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> 5<br></span><strong style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation</strong><strong style="font-size: 18px;">: <br></strong><span style="font-size: 18px;">- After 1 sec: Node 5 catches fire.
- After 2 sec: Node 2 catches fire.
- After 3 sec: Nodes 1 and 4 catch fire.
- After 4 sec: Node 3 catches fire.
- After 5 sec: Node 7 catches fire.
Total time taken to burn the entire tree: 5 seconds.</span></span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> <span class="hljs-variable">root</span><span class="hljs-punctuation">[</span><span class="hljs-punctuation">]</span> <span class="hljs-operator">=</span> <span class="hljs-punctuation">[</span><span class="hljs-number">1</span><span class="hljs-operator">,</span> <span class="hljs-number">2</span><span class="hljs-operator">,</span> <span class="hljs-number">3</span><span class="hljs-operator">,</span> <span class="hljs-number">4</span><span class="hljs-operator">,</span> <span class="hljs-number">5</span><span class="hljs-operator">,</span> <span class="hljs-number">6</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-built_in">N</span><span class="hljs-operator">,</span> <span class="hljs-number">7</span><span class="hljs-operator">,</span> <span class="hljs-number">8</span><span class="hljs-punctuation">]</span><span class="hljs-operator">,</span> <span class="hljs-variable">target</span> <span class="hljs-operator">=</span> <span class="hljs-number">4</span>
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10</span>
<span style="font-size: 18px;"><strong>Output:</strong> 4<br><strong style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation</strong><strong>: <br></strong>If the node with the value 4 is set on fire:
- After 1 sec: Node 2 catches fire.
- After 2 sec: Nodes 1 and 5 catch fire.
- After 3 sec: Node 3 catches fire.
- After 4 sec: Nodes 6, 7, and 8 catch fire.
Total time taken to burn the entire tree: 4 seconds.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤&nbsp;</span><span style="font-size: 18px;">number of nodes</span><span style="font-size: 18px;">&nbsp;≤ 10</span><sup>5<br></sup><span style="font-size: 18px;">1 ≤ node-&gt;data</span><span style="font-size: 18px;">&nbsp;≤ 10</span><sup>5</sup></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;