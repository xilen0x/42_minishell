<div class="row align-items-md-stretch">
  <div class="col-md-6">
    <div class="h-100 p-5 border card-color rounded-3">
      <h2>Minishell Project</h2>
      <p>The **minishell** project involves creating a simplified version of a shell, similar to bash, with the following functionalities:</p>

      <h4>User Interface</h4>
      <ul>
        <li>Displays a prompt when waiting for a new command.</li>
        <li>Includes a functional command history.</li>
      </ul>

      <h4>Command Execution</h4>
      <ul>
        <li>Searches for and launches the correct executable based on the PATH variable or using a relative or absolute path.</li>
      </ul>

      <h4>Signal Handling</h4>
      <ul>
        <li>Avoids using more than one global variable to indicate a received signal, ensuring that the signal handler does not access main data structures.</li>
      </ul>

      <h4>Quotes and Special Characters</h4>
      <ul>
        <li>Does not interpret unclosed quotes or unnecessary special characters such as \ (backslash) or ; (semicolon).</li>
        <li>Handles single quotes (') to prevent the shell from interpreting metacharacters in the quoted sequence.</li>
        <li>Handles double quotes (") to prevent the shell from interpreting metacharacters in the quoted sequence except for the $ (dollar sign).</li>
      </ul>

      <h4>Redirections</h4>
      <ul>
        <li><code>&lt;</code> redirects input.</li>
        <li><code>&gt;</code> redirects output.</li>
        <li><code>&lt;&lt;</code> (heredoc) reads the input until a line containing a specified delimiter is seen, but does not update the history.</li>
        <li><code>&gt;&gt;</code> redirects output in append mode.</li>
      </ul>

      <h4>Pipes</h4>
      <ul>
        <li>Implements the <code>|</code> character to connect the output of one command to the input of the next command via a pipe.</li>
      </ul>

      <h4>Environment Variables</h4>
      <ul>
        <li>Handles environment variables, expanding to their values when <code>$</code> is followed by a sequence of characters.</li>
        <li>Handles <code>$?</code>, which expands to the exit status of the most recently executed foreground pipeline.</li>
      </ul>

      <h4>Control Signals in Interactive Mode</h4>
      <ul>
        <li><code>ctrl-C</code> displays a new prompt on a new line.</li>
        <li><code>ctrl-D</code> exits the shell.</li>
        <li><code>ctrl-\</code> does nothing.</li>
      </ul>

      <h4>Built-in Commands</h4>
      <ul>
        <li><code>echo</code> with the <code>-n</code> option.</li>
        <li><code>cd</code> with only a relative or absolute path.</li>
        <li><code>pwd</code> with no options.</li>
        <li><code>export</code> with no options.</li>
        <li><code>unset</code> with no options.</li>
        <li><code>env</code> with no options or arguments.</li>
        <li><code>exit</code> with no options.</li>
      </ul>

      <p>The goal is to create a basic shell that efficiently handles command execution, redirections, pipes, and signals, while implementing essential built-in commands.</p>

      ![game](https://raw.githubusercontent.com/xilen0x/xilen0x/master/images_x_repos/Screenshot%20from%202024-06-02%2013-26-40.png)

      [![Visit the project page](https://xilen0x.github.io/42_so_long.github.io/)](https://xilen0x.github.io/42_so_long.github.io/)
    </div>
  </div>

  <div class="col-md-6">
    <div class="h-100 p-5 border card-color rounded-3">
      <h2>The Philosophers Problem</h2>
      <p>Project that seeks to understand the concepts of threading a process, how to create threads and work with mutexes.</p>
      ![game](https://raw.githubusercontent.com/xilen0x/xilen0x/master/images_x_repos/philosophers_diagram.png)

      [![Visit the project page](https://github.com/xilen0x/42_philosophers)](https://github.com/xilen0x/42_philosophers)
    </div>
  </div>
</div>

