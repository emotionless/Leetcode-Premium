<h2><a href="https://leetcode.com/problems/alien-dictionary/">269. Alien Dictionary</a></h2><h3>Hard</h3><hr><div><p>There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.</p>

<p>You are given a list of strings <code>words</code> from the alien language's dictionary, where the strings in <code>words</code> are <span data-keyword="lexicographically-smaller-string-alien"><strong>sorted lexicographically</strong></span> by the rules of this new language.</p>

<p>Return <em>a string of the unique letters in the new alien language sorted in <strong>lexicographically increasing order</strong> by the new language's rules. </em>If there is no solution, return <code>""</code><em>. </em>If there are multiple solutions, return<em> <strong>any of them</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["wrt","wrf","er","ett","rftt"]
<strong>Output:</strong> "wertf"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["z","x"]
<strong>Output:</strong> "zx"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["z","x","z"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> The order is invalid, so return <code>""</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
</ul>
</div>