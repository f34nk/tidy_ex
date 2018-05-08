
# TidyEx Options

TidyEx supports most of the [tidy-html5 options](http://api.html-tidy.org/tidy/tidylib_api_5.6.0/group__public__enumerations.html#ga3a1401652599150188a168dade7dc150).

Set options in the app config or directly on each function call.

```elixir
config :tidy_ex, options: [{"TidyShowWarnings", "no"}, {"TidyBodyOnly", "yes"}, {"TidyQuiet", "yes"}, {"TidyVertSpace", "auto"}, {"TidyIndentSpaces", "0"}]
```

Supported options are defined in [tidy_options.h](https://github.com/f34nk/tidy_ex/blob/master/target/tidy_worker/tidy/tidy_options.h).


<table>
  <tbody>
    <tr>
      <th>Enumerator</th>
    </tr>
    <tr>
      <td>TidyUnknownOption&nbsp;</td>
      <td>
        <p>Unknown option! </p>
      </td>
    </tr>
    <!-- <tr>
      <td>TidyAccessibilityCheckLevel&nbsp;</td>
      <td>
        <p>Accessibility check level. </p>
      </td>
    </tr> -->
    <tr>
      <td>TidyAltText&nbsp;</td>
      <td>
        <p>Default text for alt attribute. </p>
      </td>
    </tr>
    <tr>
      <td>TidyAnchorAsName&nbsp;</td>
      <td>
        <p>Define anchors as name attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyAsciiChars&nbsp;</td>
      <td>
        <p>Convert quotes and dashes to nearest ASCII char. </p>
      </td>
    </tr>
    <tr>
      <td>TidyBlockTags&nbsp;</td>
      <td>
        <p>Declared block tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyBodyOnly&nbsp;</td>
      <td>
        <p>Output BODY content only. </p>
      </td>
    </tr>
    <tr>
      <td>TidyBreakBeforeBR&nbsp;</td>
      <td>
        <p>Output newline before
          <br> or not? </p>
      </td>
    </tr>
    <tr>
      <td>TidyCharEncoding&nbsp;</td>
      <td>
        <p>In/out character encoding. </p>
      </td>
    </tr>
    <tr>
      <td>TidyCoerceEndTags&nbsp;</td>
      <td>
        <p>Coerce end tags from start tags where probably intended. </p>
      </td>
    </tr>
    <tr>
      <td>TidyCSSPrefix&nbsp;</td>
      <td>
        <p>CSS class naming for clean option. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDecorateInferredUL&nbsp;</td>
      <td>
        <p>Mark inferred UL elements with no indent CSS. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDoctype&nbsp;</td>
      <td>
        <p>User specified doctype. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDropEmptyElems&nbsp;</td>
      <td>
        <p>Discard empty elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDropEmptyParas&nbsp;</td>
      <td>
        <p>Discard empty p elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDropPropAttrs&nbsp;</td>
      <td>
        <p>Discard proprietary attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyDuplicateAttrs&nbsp;</td>
      <td>
        <p>Keep first or last duplicate attribute. </p>
      </td>
    </tr>
    <tr>
      <td>TidyEmacs&nbsp;</td>
      <td>
        <p>If true, format error output for GNU Emacs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyEmptyTags&nbsp;</td>
      <td>
        <p>Declared empty tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyEncloseBlockText&nbsp;</td>
      <td>
        <p>If yes text in blocks is wrapped in P's. </p>
      </td>
    </tr>
    <tr>
      <td>TidyEncloseBodyText&nbsp;</td>
      <td>
        <p>If yes text at body is wrapped in P's. </p>
      </td>
    </tr>
    <!-- <tr>
      <td>TidyErrFile&nbsp;</td>
      <td>
        <p>File name to write errors to. </p>
      </td>
    </tr> -->
    <tr>
      <td>TidyEscapeCdata&nbsp;</td>
      <td>
        <p>Replace &lt;![CDATA[]]&gt; sections with escaped text. </p>
      </td>
    </tr>
    <tr>
      <td>TidyEscapeScripts&nbsp;</td>
      <td>
        <p>Escape items that look like closing tags in script tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyFixBackslash&nbsp;</td>
      <td>
        <p>Fix URLs by replacing \ with /. </p>
      </td>
    </tr>
    <tr>
      <td>TidyFixComments&nbsp;</td>
      <td>
        <p>Fix comments with adjacent hyphens. </p>
      </td>
    </tr>
    <tr>
      <td>TidyFixUri&nbsp;</td>
      <td>
        <p>Applies URI encoding if necessary. </p>
      </td>
    </tr>
    <tr>
      <td>TidyForceOutput&nbsp;</td>
      <td>
        <p>Output document even if errors were found. </p>
      </td>
    </tr>
    <tr>
      <td>TidyGDocClean&nbsp;</td>
      <td>
        <p>Clean up HTML exported from Google Docs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyHideComments&nbsp;</td>
      <td>
        <p>Hides all (real) comments in output. </p>
      </td>
    </tr>
    <tr>
      <td>TidyHtmlOut&nbsp;</td>
      <td>
        <p>Output plain HTML, even for XHTML input. </p>
      </td>
    </tr>
    <tr>
      <td>TidyInCharEncoding&nbsp;</td>
      <td>
        <p>Input character encoding (if different) </p>
      </td>
    </tr>
    <tr>
      <td>TidyIndentAttributes&nbsp;</td>
      <td>
        <p>Newline+indent before each attribute. </p>
      </td>
    </tr>
    <tr>
      <td>TidyIndentCdata&nbsp;</td>
      <td>
        <p>Indent &lt;!CDATA[ ... </p>
        <p>]]&gt; section </p>
      </td>
    </tr>
    <tr>
      <td>TidyIndentContent&nbsp;</td>
      <td>
        <p>Indent content of appropriate tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyIndentSpaces&nbsp;</td>
      <td>
        <p>Indentation n spaces/tabs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyInlineTags&nbsp;</td>
      <td>
        <p>Declared inline tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyJoinClasses&nbsp;</td>
      <td>
        <p>Join multiple class attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyJoinStyles&nbsp;</td>
      <td>
        <p>Join multiple style attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyKeepFileTimes&nbsp;</td>
      <td>
        <p>If yes last modied time is preserved. </p>
      </td>
    </tr>
    <tr>
      <td>TidyKeepTabs&nbsp;</td>
      <td>
        <p>If yes keep input source tabs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyLiteralAttribs&nbsp;</td>
      <td>
        <p>If true attributes may use newlines. </p>
      </td>
    </tr>
    <tr>
      <td>TidyLogicalEmphasis&nbsp;</td>
      <td>
        <p>Replace i by em and b by strong. </p>
      </td>
    </tr>
    <tr>
      <td>TidyLowerLiterals&nbsp;</td>
      <td>
        <p>Folds known attribute values to lower case. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMakeBare&nbsp;</td>
      <td>
        <p>Make bare HTML: remove Microsoft cruft. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMakeClean&nbsp;</td>
      <td>
        <p>Replace presentational clutter by style rules. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMark&nbsp;</td>
      <td>
        <p>Add meta element indicating tidied doc. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMergeDivs&nbsp;</td>
      <td>
        <p>Merge multiple DIVs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMergeEmphasis&nbsp;</td>
      <td>
        <p>Merge nested B and I elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMergeSpans&nbsp;</td>
      <td>
        <p>Merge multiple SPANs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMetaCharset&nbsp;</td>
      <td>
        <p>Adds/checks/fixes meta charset in the head, based on document type. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMuteReports&nbsp;</td>
      <td>
        <p>Filter these messages from output. </p>
      </td>
    </tr>
    <tr>
      <td>TidyMuteShow&nbsp;</td>
      <td>
        <p>Show message ID's in the error table. </p>
      </td>
    </tr>
    <tr>
      <td>TidyNCR&nbsp;</td>
      <td>
        <p>Allow numeric character references. </p>
      </td>
    </tr>
    <tr>
      <td>TidyNewline&nbsp;</td>
      <td>
        <p>Output line ending (default to platform) </p>
      </td>
    </tr>
    <tr>
      <td>TidyNumEntities&nbsp;</td>
      <td>
        <p>Use numeric entities. </p>
      </td>
    </tr>
    <tr>
      <td>TidyOmitOptionalTags&nbsp;</td>
      <td>
        <p>Suppress optional start tags and end tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyOutCharEncoding&nbsp;</td>
      <td>
        <p>Output character encoding (if different) </p>
      </td>
    </tr>
    <!-- <tr>
      <td>TidyOutFile&nbsp;</td>
      <td>
        <p>File name to write markup to. </p>
      </td>
    </tr> -->
   <!--  <tr>
      <td>TidyOutputBOM&nbsp;</td>
      <td>
        <p>Output a Byte Order Mark (BOM) for UTF-16 encodings. </p>
      </td>
    </tr> -->
    <tr>
      <td>TidyPPrintTabs&nbsp;</td>
      <td>
        <p>Indent using tabs istead of spaces. </p>
      </td>
    </tr>
    <tr>
      <td>TidyPreserveEntities&nbsp;</td>
      <td>
        <p>Preserve entities. </p>
      </td>
    </tr>
    <tr>
      <td>TidyPreTags&nbsp;</td>
      <td>
        <p>Declared pre tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyPriorityAttributes&nbsp;</td>
      <td>
        <p>Attributes to place first in an element. </p>
      </td>
    </tr>
    <tr>
      <td>TidyPunctWrap&nbsp;</td>
      <td>
        <p>consider punctuation and breaking spaces for wrapping </p>
      </td>
    </tr>
    <tr>
      <td>TidyQuiet&nbsp;</td>
      <td>
        <p>No 'Parsing X', guessed DTD or summary. </p>
      </td>
    </tr>
    <tr>
      <td>TidyQuoteAmpersand&nbsp;</td>
      <td>
        <p>Output naked ampersand as &amp;. </p>
      </td>
    </tr>
    <tr>
      <td>TidyQuoteMarks&nbsp;</td>
      <td>
        <p>Output " marks as ". </p>
      </td>
    </tr>
    <tr>
      <td>TidyQuoteNbsp&nbsp;</td>
      <td>
        <p>Output non-breaking space as entity. </p>
      </td>
    </tr>
    <tr>
      <td>TidyReplaceColor&nbsp;</td>
      <td>
        <p>Replace hex color attribute values with names. </p>
      </td>
    </tr>
    <tr>
      <td>TidyShowErrors&nbsp;</td>
      <td>
        <p>Number of errors to put out. </p>
      </td>
    </tr>
    <tr>
      <td>TidyShowInfo&nbsp;</td>
      <td>
        <p>If true, info-level messages are shown. </p>
      </td>
    </tr>
    <tr>
      <td>TidyShowMarkup&nbsp;</td>
      <td>
        <p>If false, normal output is suppressed. </p>
      </td>
    </tr>
    <tr>
      <td>TidyShowMetaChange&nbsp;</td>
      <td>
        <p>show when meta http-equiv content charset was changed - compatibility </p>
      </td>
    </tr>
    <tr>
      <td>TidyShowWarnings&nbsp;</td>
      <td>
        <p>However errors are always shown. </p>
      </td>
    </tr>
    <tr>
      <td>TidySkipNested&nbsp;</td>
      <td>
        <p>Skip nested tags in script and style CDATA. </p>
      </td>
    </tr>
    <tr>
      <td>TidySortAttributes&nbsp;</td>
      <td>
        <p>Sort attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyStrictTagsAttr&nbsp;</td>
      <td>
        <p>Ensure tags and attributes match output HTML version. </p>
      </td>
    </tr>
    <tr>
      <td>TidyStyleTags&nbsp;</td>
      <td>
        <p>Move sytle to head. </p>
      </td>
    </tr>
    <tr>
      <td>TidyTabSize&nbsp;</td>
      <td>
        <p>Expand tabs to n spaces. </p>
      </td>
    </tr>
    <tr>
      <td>TidyUpperCaseAttrs&nbsp;</td>
      <td>
        <p>Output attributes in upper not lower case. </p>
      </td>
    </tr>
    <tr>
      <td>TidyUpperCaseTags&nbsp;</td>
      <td>
        <p>Output tags in upper not lower case. </p>
      </td>
    </tr>
    <tr>
      <td>TidyUseCustomTags&nbsp;</td>
      <td>
        <p>Enable Tidy to use autonomous custom tags. </p>
      </td>
    </tr>
    <tr>
      <td>TidyVertSpace&nbsp;</td>
      <td>
        <p>degree to which markup is spread out vertically </p>
      </td>
    </tr>
    <tr>
      <td>TidyWarnPropAttrs&nbsp;</td>
      <td>
        <p>Warns on proprietary attributes. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWord2000&nbsp;</td>
      <td>
        <p>Draconian cleaning for Word2000. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapAsp&nbsp;</td>
      <td>
        <p>Wrap within ASP pseudo elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapAttVals&nbsp;</td>
      <td>
        <p>Wrap within attribute values. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapJste&nbsp;</td>
      <td>
        <p>Wrap within JSTE pseudo elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapLen&nbsp;</td>
      <td>
        <p>Wrap margin. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapPhp&nbsp;</td>
      <td>
        <p>Wrap within PHP pseudo elements. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapScriptlets&nbsp;</td>
      <td>
        <p>Wrap within JavaScript string literals. </p>
      </td>
    </tr>
    <tr>
      <td>TidyWrapSection&nbsp;</td>
      <td>
        <p>Wrap within &lt;![ ... </p>
        <p>]&gt; section tags </p>
      </td>
    </tr>
    <tr>
      <td>TidyWriteBack&nbsp;</td>
      <td>
        <p>If true then output tidied markup. </p>
      </td>
    </tr>
    <tr>
      <td>TidyXhtmlOut&nbsp;</td>
      <td>
        <p>Output extensible HTML. </p>
      </td>
    </tr>
    <tr>
      <td>TidyXmlDecl&nbsp;</td>
      <td>
        <p>Add &lt;?xml?&gt; for XML docs. </p>
      </td>
    </tr>
    <tr>
      <td>TidyXmlOut&nbsp;</td>
      <td>
        <p>Create output as XML. </p>
      </td>
    </tr>
    <tr>
      <td>TidyXmlPIs&nbsp;</td>
      <td>
        <p>If set to yes PIs must end with ?&gt; </p>
      </td>
    </tr>
    <tr>
      <td>TidyXmlSpace&nbsp;</td>
      <td>
        <p>If set to yes adds xml:space attr as needed. </p>
      </td>
    </tr>
    <tr>
      <td>TidyXmlTags&nbsp;</td>
      <td>
        <p>Treat input as XML. </p>
      </td>
    </tr>
    <tr>
      <td>N_TIDY_OPTIONS&nbsp;</td>
      <td>
        <p>Must be last. </p>
      </td>
    </tr>
  </tbody>
</table>