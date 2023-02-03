<h2><a href="https://leetcode.com/problems/flip-game-ii/">294. Flip Game II</a></h2><h3>Medium</h3><hr><div><p>You are playing a Flip Game with your friend.</p>

<p>You are given a string <code>currentState</code> that contains only <code>'+'</code> and <code>'-'</code>. You and your friend take turns to flip <strong>two consecutive</strong> <code>"++"</code> into <code>"--"</code>. The game ends when a person can no longer make a move, and therefore the other person will be the winner.</p>

<p>Return <code>true</code> <em>if the starting player can <strong>guarantee a win</strong></em>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> currentState = "++++"
<strong>Output:</strong> true
<strong>Explanation:</strong> The starting player can guarantee a win by flipping the middle "++" to become "+--+".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> currentState = "+"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= currentState.length &lt;= 60</code></li>
	<li><code>currentState[i]</code> is either <code>'+'</code> or <code>'-'</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Derive your algorithm's runtime complexity.</div>