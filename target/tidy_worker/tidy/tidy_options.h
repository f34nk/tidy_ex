#ifndef TIDY_OPTIONS_H
#define TIDY_OPTIONS_H

/*
 Copyright (C) 2018 Frank Eickhoff

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, 
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <tidy.h>
#include <tidybuffio.h>

/*
TidyOptionId to string conversion

Reference:
http://api.html-tidy.org/tidy/tidylib_api_5.6.0/group__public__enumerations.html#ga3a1401652599150188a168dade7dc150
*/
const static struct {
  TidyOptionId value;
  const char* string;
} conversion [] = {
  // TidyAccessibilityCheckLevel, // Accessibility check level
  {TidyAltText, "TidyAltText"}, // Default text for alt attribute
  {TidyAnchorAsName, "TidyAnchorAsName"}, // Define anchors as name attributes
  // TidyAsciiChars, // Convert quotes and dashes to nearest ASCII char
  // TidyBlockTags, // Declared block tags
  {TidyBodyOnly, "TidyBodyOnly"}, // Output BODY content only
  {TidyBreakBeforeBR, "TidyBreakBeforeBR"}, // Output newline before <br> or not?
  // TidyCharEncoding, // In/out character encoding
  // TidyCoerceEndTags, // Coerce end tags from start tags where probably intended
  {TidyCSSPrefix, "TidyCSSPrefix"}, // CSS class naming for clean option
  // #ifndef DOXYGEN_SHOULD_SKIP_THIS
  // TidyCustomTags, // Internal use ONLY
  // #endif
  // TidyDecorateInferredUL, // Mark inferred UL elements with no indent CSS
  // TidyDoctype, // User specified doctype
  // #ifndef DOXYGEN_SHOULD_SKIP_THIS
  // TidyDoctypeMode, // Internal use ONLY
  // #endif
  {TidyDropEmptyElems, "TidyDropEmptyElems"}, // Discard empty elements
  {TidyDropEmptyParas, "TidyDropEmptyParas"}, // Discard empty p elements
  {TidyDropPropAttrs, "TidyDropPropAttrs"}, // Discard proprietary attributes
  {TidyDuplicateAttrs, "TidyDuplicateAttrs"}, // Keep first or last duplicate attribute
  // TidyEmacs, // If true, format error output for GNU Emacs
  // #ifndef DOXYGEN_SHOULD_SKIP_THIS
  // TidyEmacsFile, // Internal use ONLY
  // #endif
  {TidyEmptyTags, "TidyEmptyTags"}, // Declared empty tags
  {TidyEncloseBlockText, "TidyEncloseBlockText"}, // If yes text in blocks is wrapped in P's
  {TidyEncloseBodyText, "TidyEncloseBodyText"}, // If yes text at body is wrapped in P's
  // TidyErrFile, // File name to write errors to
  {TidyEscapeCdata, "TidyEscapeCdata"}, // Replace <![CDATA[]]> sections with escaped text
  {TidyEscapeScripts, "TidyEscapeScripts"}, // Escape items that look like closing tags in script tags
  {TidyFixBackslash, "TidyFixBackslash"}, // Fix URLs by replacing \ with /
  {TidyFixComments, "TidyFixComments"}, // Fix comments with adjacent hyphens
  {TidyFixUri, "TidyFixUri"}, // Applies URI encoding if necessary
  {TidyForceOutput, "TidyForceOutput"}, // Output document even if errors were found
  {TidyGDocClean, "TidyGDocClean"}, // Clean up HTML exported from Google Docs
  {TidyHideComments, "TidyHideComments"}, // Hides all (real) comments in output
  {TidyHtmlOut, "TidyHtmlOut"}, // Output plain HTML, even for XHTML input.*/
  // TidyInCharEncoding, // Input character encoding (if different)
  {TidyIndentAttributes, "TidyIndentAttributes"}, // Newline+indent before each attribute
  {TidyIndentCdata, "TidyIndentCdata"}, // Indent <!CDATA[ ... ]]> section
  {TidyIndentContent, "TidyIndentContent"}, // Indent content of appropriate tags
  {TidyIndentSpaces, "TidyIndentSpaces"}, // Indentation n spaces/tabs
  {TidyInlineTags, "TidyInlineTags"}, // Declared inline tags
  {TidyJoinClasses, "TidyJoinClasses"}, // Join multiple class attributes
  {TidyJoinStyles, "TidyJoinStyles"}, // Join multiple style attributes
  {TidyKeepFileTimes, "TidyKeepFileTimes"}, // If yes last modied time is preserved
  {TidyKeepTabs, "TidyKeepTabs"}, // If yes keep input source tabs
  {TidyLiteralAttribs, "TidyLiteralAttribs"}, // If true attributes may use newlines
  {TidyLogicalEmphasis, "TidyLogicalEmphasis"}, // Replace i by em and b by strong
  {TidyLowerLiterals, "TidyLowerLiterals"}, // Folds known attribute values to lower case
  {TidyMakeBare, "TidyMakeBare"}, // Make bare HTML: remove Microsoft cruft
  {TidyMakeClean, "TidyMakeClean"}, // Replace presentational clutter by style rules
  {TidyMark, "TidyMark"}, // Add meta element indicating tidied doc
  {TidyMergeDivs, "TidyMergeDivs"}, // Merge multiple DIVs
  {TidyMergeEmphasis, "TidyMergeEmphasis"}, //*< Merge nested B and I elements
  {TidyMergeSpans, "TidyMergeSpans"}, // Merge multiple SPANs
  {TidyMetaCharset, "TidyMetaCharset"}, // Adds/checks/fixes meta charset in the head, based on document type
  // TidyMuteReports, // Filter these messages from output.
  // TidyMuteShow, // Show message ID's in the error table
  {TidyNCR, "TidyNCR"}, // Allow numeric character references
  {TidyNewline, "TidyNewline"}, // Output line ending (default to platform)
  {TidyNumEntities, "TidyNumEntities"}, // Use numeric entities
  // TidyOmitOptionalTags, // Suppress optional start tags and end tags
  // TidyOutCharEncoding, // Output character encoding (if different)
  // TidyOutFile, // File name to write markup to
  // TidyOutputBOM, // Output a Byte Order Mark (BOM) for UTF-16 encodings
  {TidyPPrintTabs, "TidyPPrintTabs"}, // Indent using tabs istead of spaces
  {TidyPreserveEntities, "TidyPreserveEntities"}, // Preserve entities
  {TidyPreTags, "TidyPreTags"}, // Declared pre tags
  {TidyPriorityAttributes, "TidyPriorityAttributes"}, // Attributes to place first in an element
  {TidyPunctWrap, "TidyPunctWrap"}, // consider punctuation and breaking spaces for wrapping
  {TidyQuiet, "TidyQuiet"}, // No 'Parsing X', guessed DTD or summary
  {TidyQuoteAmpersand, "TidyQuoteAmpersand"}, // Output naked ampersand as &amp;
  {TidyQuoteMarks, "TidyQuoteMarks"}, // Output " marks as &quot;
  {TidyQuoteNbsp, "TidyQuoteNbsp"}, // Output non-breaking space as entity
  {TidyReplaceColor, "TidyReplaceColor"}, // Replace hex color attribute values with names
  // TidyShowErrors, // Number of errors to put out
  // TidyShowInfo, // If true, info-level messages are shown
  // TidyShowMarkup, // If false, normal output is suppressed
  // TidyShowMetaChange, // show when meta http-equiv content charset was changed - compatibility
  {TidyShowWarnings, "TidyShowWarnings"}, // However errors are always shown
  {TidySkipNested, "TidySkipNested"}, // Skip nested tags in script and style CDATA
  {TidySortAttributes, "TidySortAttributes"}, // Sort attributes
  {TidyStrictTagsAttr, "TidyStrictTagsAttr"}, // Ensure tags and attributes match output HTML version
  {TidyStyleTags, "TidyStyleTags"}, // Move sytle to head
  {TidyTabSize, "TidyTabSize"}, // Expand tabs to n spaces
  {TidyUpperCaseAttrs, "TidyUpperCaseAttrs"}, // Output attributes in upper not lower case
  {TidyUpperCaseTags, "TidyUpperCaseTags"}, // Output tags in upper not lower case
  {TidyUseCustomTags, "TidyUseCustomTags"}, // Enable Tidy to use autonomous custom tags
  {TidyVertSpace, "TidyVertSpace"}, // degree to which markup is spread out vertically
  // TidyWarnPropAttrs, // Warns on proprietary attributes
  // TidyWord2000, // Draconian cleaning for Word2000
  {TidyWrapAsp, "TidyWrapAsp"}, // Wrap within ASP pseudo elements
  {TidyWrapAttVals, "TidyWrapAttVals"}, // Wrap within attribute values
  // TidyWrapJste, // Wrap within JSTE pseudo elements
  {TidyWrapLen, "TidyWrapLen"}, // Wrap margin
  {TidyWrapPhp, "TidyWrapPhp"}, // Wrap within PHP pseudo elements
  {TidyWrapScriptlets, "TidyWrapScriptlets"}, // Wrap within JavaScript string literals
  {TidyWrapSection, "TidyWrapSection"}, // Wrap within <![ ... ]> section tags
  // TidyWriteBack, // If true then output tidied markup
  {TidyXhtmlOut, "TidyXhtmlOut"}, // Output extensible HTML
  {TidyXmlDecl, "TidyXmlDecl"}, // Add <?xml?> for XML docs
  {TidyXmlOut, "TidyXmlOut"}, // Create output as XML
  {TidyXmlPIs, "TidyXmlPIs"}, // If set to yes PIs must end with ?>
  {TidyXmlSpace, "TidyXmlSpace"}, // If set to yes adds xml:space attr as needed
  {TidyXmlTags, "TidyXmlTags"}, // Treat input as XML
};

#endif