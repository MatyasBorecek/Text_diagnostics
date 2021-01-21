# Text diagnostics
(CZ)
<ol type="1">
<li>Ze standardního vstupu načtěte řádek, který bude obsahovat cestu ke vstupnímu souboru s textem (říkejme tomuto souboru <code>I</code>). Nad tímto souborem budete počítat textové statistiky.
<ul>
<li>V tomto souboru bude několik řádků, na každém řádku bude několik slov oddělených jednou mezerou. Na řádku bude nejvýše <code>512</code> znaků.</li>
<li>Za posledním slovem na řádku není mezera, ale odřádkování (<code>\n</code>). Odřádkování se nebere v potaz pro výpočet statistik.</li>
<li>Všechna slova se budou skládat pouze z ASCII znaků.</li>
</ul>
</li>
<li>Ze standardního vstupu načtěte druhý řádek, který bude obsahovat cestu k výstupnímu souboru (říkejme tomuto souboru <code>O</code>).</li>
<li>Ze standardního vstupu dále postupně načítejte řádky. Na každém řádku bude jeden z následujících řetězců, které popisují statistiku, kterou máte vypočítat z textu v souboru <code>I</code>:</li>
</ol>
<ul>
<li>
<p><code>row-ends-with &lt;char&gt;</code></p>
<p>Vypočti počet řádků, které končí znakem <code>&lt;char&gt;</code>. Pokud by byl např. <code>&lt;char&gt;</code> roven <code>a</code>, tak na následujícím textu:</p>
<pre class="text"><code class="hljs cpp"><span class="hljs-keyword">auto</span> amanita aristokratka
akcni film borka
boure lopata kopat</code></pre>
<p>by statistika měla hodnotu <code>2</code>.</p>
</li>
<li>
<p><code>word-starts-with &lt;char&gt;</code></p>
<p>Vypočti počet slov, které začínají znakem <code>&lt;char&gt;</code>. Pokud by byl např. <code>&lt;char&gt;</code> roven <code>a</code>, tak na následujícím textu:</p>
<pre class="text"><code class="hljs cpp"><span class="hljs-keyword">auto</span> amanita aristokratka
akcni film borka
boure lopata kopat</code></pre>
<p>by statistika měla hodnotu <code>4</code>.</p>
<p>Pro každý řádek vyhodnoťte statistiku na textu v souboru <code>I</code>. Výsledkem statistiky bude jedno celé číslo, to vypište na samostatný řádek do souboru <code>O</code>. <code>&lt;char&gt;</code> bude vždy jeden ASCII znak.</p>
</li>
</ul>

- Tests
    - stdin =><pre>
      00.data_input
      00.data_output
      row-ends-with j
      word-starts-with z
      row-ends-with d</pre>
      
  - OO.data_input => <pre>
    guarachas pileweed numerates poroma emendatory
    zyzzyvas furcated anacoenoses futures homoousiast
    furnacemen malunion eutaxite bewary chaser
    tschernosem acolyth scram remaindment purpuriform
    hanukkah foster monopolized pandemoniac      </pre>
      
  - 00.data_output => <pre>
      0
      1
      0 </pre>