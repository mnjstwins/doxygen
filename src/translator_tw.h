/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2002 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef TRANSLATOR_TW_H
#define TRANSLATOR_TW_H

// When defining a translator class for the new language, follow
// the description in the documentation.  One of the steps says
// that you should copy the translator_en.h (this) file to your
// translator_xx.h new file.  Your new language should use the
// Translator class as the base class.  This means that you need to
// implement exactly the same (pure virtual) methods as the
// TranslatorEnglish does.  Because of this, it is a good idea to
// start with the copy of TranslatorEnglish and replace the strings
// one by one.
//
// It is not necessary to include "translator.h" or
// "translator_adapter.h" here.  The files are included in the
// language.cpp correctly.  Not including any of the mentioned
// files frees the maintainer from thinking about whether the
// first, the second, or both files should be included or not, and
// why.  This holds namely for localized translators because their
// base class is changed occasionaly to adapter classes when the
// Translator class changes the interface, or back to the
// Translator class (by the local maintainer) when the localized
// translator is made up-to-date again.

class TranslatorChinesetraditional : public Translator
{
  public:

    // --- Language control methods -------------------
    
    /*! Used for identification of the language. The identification 
     * should not be translated. It should be replaced by the name 
     * of the language in English using lower-case characters only
     * (e.g. "czech", "japanese", "russian", etc.). It should be equal to 
     * the identification used in language.cpp.
     */
    virtual QCString idLanguage()
    { return "chinese-traditional"; }
    
    /*! Used to get the LaTeX command(s) for the language support. 
     *  This method should return string with commands that switch
     *  LaTeX to the desired language.  For example 
     *  <pre>"\\usepackage[german]{babel}\n"
     *  </pre>
     *  or
     *  <pre>"\\usepackage{polski}\n"
     *  "\\usepackage[latin2]{inputenc}\n"
     *  "\\usepackage[T1]{fontenc}\n"
     *  </pre>
     * 
     * The English LaTeX does not use such commands.  Because of this
     * the empty string is returned in this implementation.
     */
    virtual QCString latexLanguageSupportCommand()
    {
      return "";
    }

    /*! return the language charset. This will be used for the HTML output */
    virtual QCString idLanguageCharset()
    {
      return "big5";
    }

    // --- Language translation methods -------------------

    /*! used in the compound documentation before a list of related functions. */
    virtual QCString trRelatedFunctions()
    { return "�����禡"; }

    /*! subscript for the related functions. */
    virtual QCString trRelatedSubscript()
    { return "(���G�o�Ǥ��O�����禡)"; }

    /*! header that is put before the detailed description of files, classes and namespaces. */
    virtual QCString trDetailedDescription()
    { return "�ԲӴy�z"; }

    /*! header that is put before the list of typedefs. */
    virtual QCString trMemberTypedefDocumentation()
    { return "���A�w�q�����������"; }
    
    /*! header that is put before the list of enumerations. */
    virtual QCString trMemberEnumerationDocumentation()
    { return "�C�|���A�����������"; }
    
    /*! header that is put before the list of member functions. */
    virtual QCString trMemberFunctionDocumentation()
    { return "�禡�����������"; }
    
    /*! header that is put before the list of member attributes. */
    virtual QCString trMemberDataDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "��컡�����"; 
      }
      else
      {
        return "��Ʀ����������"; 
      }
    }

    /*! this is the text of a link put after brief descriptions. */
    virtual QCString trMore() 
    { return "��h..."; }

    /*! put in the class documentation */
    virtual QCString trListOfAllMembers()
    { return "���������C��"; }

    /*! used as the title of the "list of all members" page of a class */
    virtual QCString trMemberList()
    { return "�����C��"; }

    /*! this is the first part of a sentence that is followed by a class name */
    virtual QCString trThisIsTheListOfAllMembers()
    { return "���㦨���C���A���O��"; }

    /*! this is the remainder of the sentence after the class name */
    virtual QCString trIncludingInheritedMembers()
    { return ", �]�t�Ҧ��~�Ӫ�����"; }
    
    /*! this is put at the author sections at the bottom of man pages.
     *  parameter s is name of the project name.
     */
    virtual QCString trGeneratedAutomatically(const char *s)
    { QCString result="������Doxygen";
      if (s) result+=(QCString)" �� "+s;
      result+=" ����l�X���۰ʲ���."; 
      return result;
    }

    /*! put after an enum name in the list of all members */
    virtual QCString trEnumName()
    { return "�C�|���A�W��"; }
    
    /*! put after an enum value in the list of all members */
    virtual QCString trEnumValue()
    { return "�C�|��"; }
    
    /*! put after an undocumented member in the list of all members */
    virtual QCString trDefinedIn()
    { return "�Q�w�q��"; }

    // quick reference sections

    /*! This is put above each page as a link to the list of all groups of 
     *  compounds or files (see the \\group command).
     */
    virtual QCString trModules()
    { return "�Ҳ�"; }
    
    /*! This is put above each page as a link to the class hierarchy */
    virtual QCString trClassHierarchy()
    { return "���O���h"; }
    
    /*! This is put above each page as a link to the list of annotated classes */
    virtual QCString trCompoundList()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "��Ƶ��c";
      }
      else
      {
        return "�ƦX�C��"; 
      }
    }
    
    /*! This is put above each page as a link to the list of documented files */
    virtual QCString trFileList()
    { return "�ɮצC��"; }

    /*! This is put above each page as a link to the list of all verbatim headers */
    virtual QCString trHeaderFiles()
    { return "���Y�ɮ�"; }

    /*! This is put above each page as a link to all members of compounds. */
    virtual QCString trCompoundMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "������"; 
      }
      else
      {
        return "�ƦX����"; 
      }
    }

    /*! This is put above each page as a link to all members of files. */
    virtual QCString trFileMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "������"; 
      }
      else
      {
        return "�ɮצ���"; 
      }
    }

    /*! This is put above each page as a link to all related pages. */
    virtual QCString trRelatedPages()
    { return "��������"; }

    /*! This is put above each page as a link to all examples. */
    virtual QCString trExamples()
    { return "�d��"; }

    /*! This is put above each page as a link to the search engine. */
    virtual QCString trSearch()
    { return "�j�M"; }

    /*! This is an introduction to the class hierarchy. */
    virtual QCString trClassHierarchyDescription()
    { return "�o���~�ӦC���g�L²�����r���Ƨ�: ";
    }

    /*! This is an introduction to the list with all files. */
    virtual QCString trFileListDescription(bool extractAll)
    {
      QCString result="�o�O���a²������";
      if (!extractAll) result+="�B�g�L����";
      result+="���ɮצC��:";
      return result;
    }

    /*! This is an introduction to the annotated compound list. */
    virtual QCString trCompoundListDescription()
    { 
      
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "�o�O���a²����������Ƶ��c:"; 
      }
      else
      {
        return "�o�O���a²�����������O�A���c�A"
               "�p�X���A(unions)�Τ���(interfaces):"; 
      }
    }

    /*! This is an introduction to the page with all class members. */
    virtual QCString trCompoundMembersDescription(bool extractAll)
    {
      QCString result="�o�O����";
      if (!extractAll)
      {
        result+="���ƹL";
      }
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="���c���p�X���A���";
      }
      else
      {
        result+="���O����";
      }
      result+=", �åB�a���s����";
      if (extractAll) 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="�C����쪺���c/�p�X���A�������:";
        }
        else
        {
          result+="�C�Ӧ��������O�������:";
        }
      }
      else 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="�o�ǵ��c/�p�X���A�O�ݩ�:";
        }
        else
        {
          result+="�o�����O�O�ݩ�:";
        }
      }
      return result;
    }

    /*! This is an introduction to the page with all file members. */
    virtual QCString trFileMembersDescription(bool extractAll)
    {
      QCString result="�o�O����";
      if (!extractAll) result+="���ƪ�";
      
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="�禡�A�ܼơA�w�q�A�C�|�A�Ϋ��A�w�q";
      }
      else
      {
        result+="�ɮצ���";
      }
      result+="�A�åB�a���s����";
      if (extractAll) 
        result+="�o���ɮש���:";
      else 
        result+="�������:";
      return result;
    }

    /*! This is an introduction to the page with the list of all header files. */
    virtual QCString trHeaderFilesDescription()
    { return "�զ�API�����Y��:"; }

    /*! This is an introduction to the page with the list of all examples */
    virtual QCString trExamplesDescription()
    { return "�Ҧ��d�ҦC��:"; }

    /*! This is an introduction to the page with the list of related pages */
    virtual QCString trRelatedPagesDescription()
    { return "�Ҧ�������󭶭��C��:"; }

    /*! This is an introduction to the page with the list of class/file groups */
    virtual QCString trModulesDescription()
    { return "�Ҧ��ҲզC��:"; }

    /*! This sentences is used in the annotated class/file lists if no brief
     * description is given. 
     */
    virtual QCString trNoDescriptionAvailable()
    { return "�S���i�Ϊ������y�z"; }
    
    // index titles (the project name is prepended for these) 


    /*! This is used in HTML as the title of index.html. */
    virtual QCString trDocumentation()
    { return "�������"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * index of all groups.
     */
    virtual QCString trModuleIndex()
    { return "�Ҳկ���"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * class hierarchy.
     */
    virtual QCString trHierarchicalIndex()
    { return "���h����"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index.
     */
    virtual QCString trCompoundIndex()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      { 
        return "��Ƶ��c����";
      }
      else
      {
        return "�ƦX����"; 
      }
    }

    /*! This is used in LaTeX as the title of the chapter with the
     * list of all files.
     */
    virtual QCString trFileIndex() 
    { return "�ɮׯ���"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all groups.
     */
    virtual QCString trModuleDocumentation()
    { return "�Ҳջ������"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all classes, structs and unions.
     */
    virtual QCString trClassDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "��Ƶ��c�������"; 
      }
      else
      {
        return "���O�������"; 
      }
    }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all files.
     */
    virtual QCString trFileDocumentation()
    { return "�ɮ׻������"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all examples.
     */
    virtual QCString trExampleDocumentation()
    { return "�d�һ������"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all related pages.
     */
    virtual QCString trPageDocumentation()
    { return "�����������"; }

    /*! This is used in LaTeX as the title of the document */
    virtual QCString trReferenceManual()
    { return "�ѦҤ�U"; }
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of defines
     */
    virtual QCString trDefines()
    { return "�w�q"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of function prototypes
     */
    virtual QCString trFuncProtos()
    { return "�禡�쫬"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of typedefs
     */
    virtual QCString trTypedefs()
    { return "���A�w�q"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of enumerations
     */
    virtual QCString trEnumerations()
    { return "�C�|���A"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) functions
     */
    virtual QCString trFunctions()
    { return "�禡"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trVariables()
    { return "�ܼ�"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trEnumerationValues()
    { return "�C�|��"; }
    
    /*! This is used in the documentation of a file before the list of
     *  documentation blocks for defines
     */
    virtual QCString trDefineDocumentation()
    { return "�w�q�����������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for function prototypes
     */
    virtual QCString trFunctionPrototypeDocumentation()
    { return "�禡�쫬�������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for typedefs
     */
    virtual QCString trTypedefDocumentation()
    { return "���A�w�q�������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration types
     */
    virtual QCString trEnumerationTypeDocumentation()
    { return "�C�|���A�������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration values
     */
    virtual QCString trEnumerationValueDocumentation()
    { return "�C�|�Ȼ������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for functions
     */
    virtual QCString trFunctionDocumentation()
    { return "�禡�������"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for variables
     */
    virtual QCString trVariableDocumentation()
    { return "�ܼƻ������"; }

    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds
     */
    virtual QCString trCompounds()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "��Ƶ��c"; 
      }
      else
      {
        return "�ƦX����"; 
      }
    }

    /*! This is used in the standard footer of each page and indicates when 
     *  the page was generated 
     */
    virtual QCString trGeneratedAt(const char *date,const char *projName)
    { 
      QCString result=(QCString)"���ͤ��:"+date;
      if (projName) result+=(QCString)", �M��:"+projName;
      result+=(QCString)", ���;�:";
      return result;
    }
    /*! This is part of the sentence used in the standard footer of each page.
     */
    virtual QCString trWrittenBy()
    {
      return "���g�H:";
    }

    /*! this text is put before a class diagram */
    virtual QCString trClassDiagram(const char *clName)
    {
      return (QCString)"���O"+clName+"���~�ӹ�:";
    }
    
    /*! this text is generated when the \\internal command is used. */
    virtual QCString trForInternalUseOnly()
    { return "�ȨѤ����ϥ�."; }

    /*! this text is generated when the \\reimp command is used. */
    virtual QCString trReimplementedForInternalReasons()
    { return "�]������]���s��@; ���v�TAPI."; }

    /*! this text is generated when the \\warning command is used. */
    virtual QCString trWarning()
    { return "ĵ�i"; }

    /*! this text is generated when the \\bug command is used. */
    virtual QCString trBugsAndLimitations()
    { return "���Τέ���"; }

    /*! this text is generated when the \\version command is used. */
    virtual QCString trVersion()
    { return "����"; }

    /*! this text is generated when the \\date command is used. */
    virtual QCString trDate()
    { return "���"; }

    /*! this text is generated when the \\return command is used. */
    virtual QCString trReturns()
    { return "�Ǧ^��"; }

    /*! this text is generated when the \\sa command is used. */
    virtual QCString trSeeAlso()
    { return "�Ѿ\\"; }

    /*! this text is generated when the \\param command is used. */
    virtual QCString trParameters()
    { return "�Ѽ�"; }

    /*! this text is generated when the \\exception command is used. */
    virtual QCString trExceptions()
    { return "�ҥ~"; }
    
    /*! this text is used in the title page of a LaTeX document. */
    virtual QCString trGeneratedBy()
    { return "���ͪ�:"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990307
//////////////////////////////////////////////////////////////////////////
    
    /*! used as the title of page containing all the index of all namespaces. */
    virtual QCString trNamespaceList()
    { return "�R�W�Ŷ�(name space)�C��"; }

    /*! used as an introduction to the namespace list */
    virtual QCString trNamespaceListDescription(bool extractAll)
    {
      QCString result="�o�O�Ҧ����a²��������";
      if (!extractAll) result+="���ƪ�";
      result+="�R�W�Ŷ�(namespaces):";
      return result;
    }

    /*! used in the class documentation as a header before the list of all
     *  friends of a class
     */
    virtual QCString trFriends()
    { return "���O�B��(Friends)"; }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990405
//////////////////////////////////////////////////////////////////////////
    
    /*! used in the class documentation as a header before the list of all
     * related classes 
     */
    virtual QCString trRelatedFunctionDocumentation()
    { return "���O�B�ͤά����禡�������"; }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990425
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of the HTML page of a class/struct/union */
    virtual QCString trCompoundReference(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool isTemplate)
    {
      QCString result=(QCString)clName+" ";
      switch(compType)
      {
        case ClassDef::Class:      result+=" ���O"; break;
        case ClassDef::Struct:     result+=" ���c"; break;
        case ClassDef::Union:      result+=" �p�X"; break;
        case ClassDef::Interface:  result+=" ����"; break;
        case ClassDef::Exception:  result+=" �ҥ~"; break;
      }
      if (isTemplate) result+=" �˪�";
      result+=" �Ѧ�";
      return result;
    }

    /*! used as the title of the HTML page of a file */
    virtual QCString trFileReference(const char *fileName)
    {
      QCString result=fileName;
      result+=" �ɮװѦҤ��"; 
      return result;
    }

    /*! used as the title of the HTML page of a namespace */
    virtual QCString trNamespaceReference(const char *namespaceName)
    {
      QCString result=namespaceName;
      result+=" �R�W�Ŷ�(Namespace)�ѦҤ��";
      return result;
    }
    
    virtual QCString trPublicMembers()
    { return "���}��k(Public Methods)"; }
    virtual QCString trPublicSlots()
    { return "���}����(Public Slots)"; }
    virtual QCString trSignals()
    { return "�T��(Signals)"; }
    virtual QCString trStaticPublicMembers()
    { return "�R�A���}��k(Static Public Methods)"; }
    virtual QCString trProtectedMembers()
    { return "�O�@��k(Protected Methods)"; }
    virtual QCString trProtectedSlots()
    { return "�O�@����(Protected Slots)"; }
    virtual QCString trStaticProtectedMembers()
    { return "�R�A�O�@��k(Static Protected Methods)"; }
    virtual QCString trPrivateMembers()
    { return "�p����k(Private Methods)"; }
    virtual QCString trPrivateSlots()
    { return "�p������(Private Slots)"; }
    virtual QCString trStaticPrivateMembers()
    { return "�R�A�p����k(Static Private Methods)"; }
    
    /*! this function is used to produce a comma-separated list of items.
     *  use generateMarker(i) to indicate where item i should be put.
     */
    virtual QCString trWriteList(int numEntries)
    {
      QCString result;
      int i;
      // the inherits list contain `numEntries' classes
      for (i=0;i<numEntries;i++) 
      {
        // use generateMarker to generate placeholders for the class links!
        result+=generateMarker(i); // generate marker for entry i in the list 
                                   // (order is left to right)
        
        if (i!=numEntries-1)  // not the last entry, so we need a separator
        {
          if (i<numEntries-2) // not the fore last entry 
            result+=", ";
          else                // the fore last entry
            result+=", �� ";
        }
      }
      return result; 
    }
    
    /*! used in class documentation to produce a list of base classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritsList(int numEntries)
    {
      return "�~�Ӧ� "+trWriteList(numEntries)+".";
    }

    /*! used in class documentation to produce a list of super classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritedByList(int numEntries)
    {
      return "�Q "+trWriteList(numEntries)+"�~��.";
    }

    /*! used in member documentation blocks to produce a list of 
     *  members that are hidden by this one.
     */
    virtual QCString trReimplementedFromList(int numEntries)
    {
      return "�̾�"+trWriteList(numEntries)+"���s��@.";
    }

    /*! used in member documentation blocks to produce a list of
     *  all member that overwrite the implementation of this member.
     */
    virtual QCString trReimplementedInList(int numEntries)
    {
      return "�b"+trWriteList(numEntries)+"���s��@.";
    }

    /*! This is put above each page as a link to all members of namespaces. */
    virtual QCString trNamespaceMembers()
    { return "�R�W�Ŷ�(Namespace)����"; }

    /*! This is an introduction to the page with all namespace members */
    virtual QCString trNamespaceMemberDescription(bool extractAll)
    { 
      QCString result="���B�C�����Ҧ� ";
      if (!extractAll) result+="���ƪ� ";
      result+="�R�W�Ŷ�(namespace)�����A�åB���a�s���� ";
      if (extractAll) 
        result+="�C�Ӧ������������:";
      else 
        result+="�өR�W�Ŷ����ݤ��B:";
      return result;
    }
    /*! This is used in LaTeX as the title of the chapter with the 
     *  index of all namespaces.
     */
    virtual QCString trNamespaceIndex()
    { return "�R�W�Ŷ�(Namespace)����"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all namespaces.
     */
    virtual QCString trNamespaceDocumentation()
    { return "�R�W�Ŷ�(Namespace)�������"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990522
//////////////////////////////////////////////////////////////////////////

    /*! This is used in the documentation before the list of all
     *  namespaces in a file.
     */
    virtual QCString trNamespaces()
    { return "�R�W�Ŷ�(Namespaces)"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990728
//////////////////////////////////////////////////////////////////////////

    /*! This is put at the bottom of a class documentation page and is
     *  followed by a list of files that were used to generate the page.
     */
    virtual QCString trGeneratedFromFiles(ClassDef::CompoundType compType,
        bool single)
    { // here s is one of " Class", " Struct" or " Union"
      // single is true implies a single file
      QCString result=(QCString)"��";
      switch(compType)
      {
        case ClassDef::Class:      result+="���O(class)"; break;
        case ClassDef::Struct:     result+="���c(structure)"; break;
        case ClassDef::Union:      result+="�p�X(union)"; break;
        case ClassDef::Interface:  result+="����(interface)"; break;
        case ClassDef::Exception:  result+="�ҥ~(exception)"; break;
      }
      result+=" ���O�ѤU�C�ɮפ�����";
      if (single) result+=":"; else result+=":";
      return result;
    }

    /*! This is in the (quick) index as a link to the alphabetical compound
     * list.
     */
    virtual QCString trAlphabeticalList()
    { return "�r�����ǦC��"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990901
//////////////////////////////////////////////////////////////////////////

    /*! This is used as the heading text for the retval command. */
    virtual QCString trReturnValues()
    { return "�Ǧ^��"; }

    /*! This is in the (quick) index as a link to the main page (index.html)
     */
    virtual QCString trMainPage()
    { return "�D����"; }

    /*! This is used in references to page that are put in the LaTeX 
     *  documentation. It should be an abbreviation of the word page.
     */
    virtual QCString trPageAbbreviation()
    { return "p."; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991003
//////////////////////////////////////////////////////////////////////////

    virtual QCString trSources()
    {
      return "��l�X";
    }
    virtual QCString trDefinedAtLineInSourceFile()
    {
      return "�w�q�b @1 �ɮפ��� @0 ��.";
    }
    virtual QCString trDefinedInSourceFile()
    {
      return "�w�q�b @0 ��.";
    }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991205
//////////////////////////////////////////////////////////////////////////

    virtual QCString trDeprecated()
    {
      return "�L��";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.0.0
//////////////////////////////////////////////////////////////////////////

    /*! this text is put before a collaboration diagram */
    virtual QCString trCollaborationDiagram(const char *clName)
    {
      return (QCString)""+clName+"���X�@��:";
    }
    /*! this text is put before an include dependency graph */
    virtual QCString trInclDepGraph(const char *fName)
    {
      return (QCString)""+fName+"���]�t�̹ۨ�:";
    }
    /*! header that is put before the list of constructor/destructors. */
    virtual QCString trConstructorDocumentation()
    {
      return "�غc�l�P�Ѻc�l�������"; 
    }
    /*! Used in the file documentation to point to the corresponding sources. */
    virtual QCString trGotoSourceCode()
    {
      return "�d�ݥ��ɮת���l�X.";
    }
    /*! Used in the file sources to point to the corresponding documentation. */
    virtual QCString trGotoDocumentation()
    {
      return "�d�ݥ��ɮ׻������.";
    }
    /*! Text for the \\pre command */
    virtual QCString trPrecondition()
    {
      return "�e�m����";
    }
    /*! Text for the \\post command */
    virtual QCString trPostcondition()
    {
      return "��m����";
    }
    /*! Text for the \\invariant command */
    virtual QCString trInvariant()
    {
      return "�`��";
    }
    /*! Text shown before a multi-line variable/enum initialization */
    virtual QCString trInitialValue()
    {
      return "���:";
    }
    /*! Text used the source code in the file index */
    virtual QCString trCode()
    {
      return "�{���X";
    }
    virtual QCString trGraphicalHierarchy()
    {
      return "�ϧΤƤ����O���h";
    }
    virtual QCString trGotoGraphicalHierarchy()
    {
      return "�d�ݹϧΤƤ����O���h";
    }
    virtual QCString trGotoTextualHierarchy()
    {
      return "�d�ݤ�r�Ƥ����O���h";
    }
    virtual QCString trPageIndex()
    {
      return "��������";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.0
//////////////////////////////////////////////////////////////////////////
    
    virtual QCString trNote()
    {
      return "��";
    }
    virtual QCString trPublicTypes()
    {
      return "���}���A";
    }
    virtual QCString trPublicAttribs()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "������";
      }
      else
      {
        return "���}�ݩ�";
      }
    }
    virtual QCString trStaticPublicAttribs()
    {
      return "�R�A���}�ݩ�";
    }
    virtual QCString trProtectedTypes()
    {
      return "�O�@���A";
    }
    virtual QCString trProtectedAttribs()
    {
      return "�O�@�ݩ�";
    }
    virtual QCString trStaticProtectedAttribs()
    {
      return "�R�A�O�@�ݩ�";
    }
    virtual QCString trPrivateTypes()
    {
      return "�p�����A";
    }
    virtual QCString trPrivateAttribs()
    {
      return "�p���ݩ�";
    }
    virtual QCString trStaticPrivateAttribs()
    {
      return "�R�A�p���ݩ�";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a marker that is put before a \\todo item */
    virtual QCString trTodo()
    {
      return "�ݿ�ƶ�";
    }
    /*! Used as the header of the todo list */
    virtual QCString trTodoList()
    {
      return "�ݿ�ƶ��C��";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.4
//////////////////////////////////////////////////////////////////////////

    virtual QCString trReferencedBy()
    {
      return "�Q�Ѧҩ�";
    }
    virtual QCString trRemarks()
    {
      return "�Ƶ�";
    }
    virtual QCString trAttention()
    {
      return "�`�N";
    }
    virtual QCString trInclByDepGraph()
    {
      return "������ܥX�����ɮת����ζ���include���� "
             ":";
    }
    virtual QCString trSince()
    {
      return "��";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.1.5
//////////////////////////////////////////////////////////////////////////

    /*! title of the graph legend page */
    virtual QCString trLegendTitle()
    {
      return "�ϥ�";
    }
    /*! page explaining how the dot graph's should be interpreted 
     *  The %A in the text below are to prevent link to classes called "A".
     */
    virtual QCString trLegendDocs()
    {
      return 
        "���������p���Ķ�o�ǥ�doxygen�Ҳ��ͪ��ϥ� "
        ".<p>\n"
        "�ЬݤU���d��:\n"
        "\\code\n"
        "/*! �]���I�_�����i�����O */\n"
        "class Invisible { };\n\n"
        "/*! �I�_�����O, �~�����Y�Q���� */\n"
        "class Truncated : public Invisible { };\n\n"
        "/* ���g�Ldoxygen���ѳB�z�L�����O */\n"
        "class Undocumented { };\n\n"
        "/*! �g�L���}(Public)�~�Ӫ����O */\n"
        "class PublicBase : public Truncated { };\n\n"
        "/*! �@�Ӽ˪����O */\n"
        "template<class T> class Templ { };\n\n"
        "/*! �ϥΫO�@(Protected)�~�Ӫ����O */\n"
        "class ProtectedBase { };\n\n"
        "/*! �ϥΨp��(Private)�~�Ӫ����O */\n"
        "class PrivateBase { };\n\n"
        "/*! �ѳQ�~�����O�ҨϥΪ����O */\n"
        "class Used { };\n\n"
        "/*! �ѼƭӨ�L���O���~�ӨӪ��W���O(Super Class) */\n"
        "class Inherited : public PublicBase,\n"
        "                  protected ProtectedBase,\n"
        "                  private PrivateBase,\n"
        "                  public Undocumented\n"
        "                  public Templ<int>\n"
        "{\n"
        "  private:\n"
        "    Used *m_usedClass;\n"
        "};\n"
        "\\endcode\n"
        "�Y�b�պA�ɤ��� \\c MAX_DOT_GRAPH_HEIGHT tag "
        "�]�� 240�A�N�|���ͤU�C���ϥ�:"
        "<p><center><img src=\"graph_legend."+Config_getEnum("DOT_IMAGE_FORMAT")+"\"></center>\n"
        "<p>\n"
        "�W�Ϥ����U�϶��N�q�p�U:\n"
        "<ul>\n"
        "<li>%A �񺡶¦⪺�϶��N�����ͳo�ӹϥܪ����O�ε��c "
        ".\n"
        "<li>%A ���䪺�϶��N�����ƹL�����c�����O.\n"
        "<li>%A ���䪺�϶��N�����g���ƪ����c�άO���O.\n"
        "<li>%A ���䪺�϶��N�����ƪ����c�άO���O�A"
        "�o�ǵ��c�����O���~�өΥ]�t���Y���|�������. %A �ϥ� "
        "�Y�L�k��J���w����ɤ��N�|�Q�I�_.\n"
        "</ul>\n"
        "�b�Y�㦳�U�����N�q:\n"
        "<ul>\n"
        "<li>%A �`�Ŧ�b�Y�ΨӥN��������O�������}�~�� "
        "���Y.\n"
        "<li>%A �`���b�Y�N���O�@�~��.\n"
        "<li>%A �`����b�Y�N���p���~��.\n"
        "<li>%A ����b�Y�ΨӪ������O�Q�t�@�ӥ]�t�άO�ϥ�."
        "�b�Y�W�Хܵۥi�s�������O�άO���c�������ܼ�"
        ".\n"
        "<li>%A ����b�Y�N���˪�����P�˪����O���������Y�C"
        "�b�Y�W�аO�ۼ˪�����W���Ѽ�"
        ".\n"
        "</ul>\n";
    }
    /*! text for the link to the legend page */
    virtual QCString trLegend()
    {
      return "�ϥ�";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.2.0
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a test item */
    virtual QCString trTest()
    {
      return "���ն���";
    }
    /*! Used as the header of the test list */
    virtual QCString trTestList()
    {
      return "���ն��ئC��";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.1
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for KDE-2 IDL methods */
    virtual QCString trDCOPMethods()
    {
      return "DCOP��k";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.2
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for IDL properties */
    virtual QCString trProperties()
    {
      return "�ݩ�(properties)";
    }
    /*! Used as a section header for IDL property documentation */
    virtual QCString trPropertyDocumentation()
    {
      return "�ݩ�(property)�������";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.4
//////////////////////////////////////////////////////////////////////////

    /*! Used for Java interfaces in the summary section of Java packages */
    virtual QCString trInterfaces()
    {
      return "����";
    }
    /*! Used for Java classes in the summary section of Java packages */
    virtual QCString trClasses()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "��Ƶ��c";
      }
      else
      {
        return "���O";
      }
    }
    /*! Used as the title of a Java package */
    virtual QCString trPackage(const char *name)
    {
      return (QCString)"Package "+name;
    }
    /*! Title of the package index page */
    virtual QCString trPackageList()
    {
      return "Package�C��";
    }
    /*! The description of the package index page */
    virtual QCString trPackageListDescription()
    {
      return "���B��Package����������(�p�G������):";
    }
    /*! The link name in the Quick links header for each page */
    virtual QCString trPackages()
    {
      return "Packages";
    }
    /*! Used as a chapter title for Latex & RTF output */
    virtual QCString trPackageDocumentation()
    {
      return "Package�������";
    }
    /*! Text shown before a multi-line define */
    virtual QCString trDefineValue()
    {
      return "��:";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.2.5
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a \\bug item */
    virtual QCString trBug()
    {
      return "����";
    }
    /*! Used as the header of the bug list */
    virtual QCString trBugList()
    {
      return "���ΦC��";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.6
//////////////////////////////////////////////////////////////////////////

    /*! Used as ansicpg for RTF file 
     * 
     * The following table shows the correlation of Charset name, Charset Value and 
     * <pre>
     * Codepage number:
     * Charset Name       Charset Value(hex)  Codepage number
     * ------------------------------------------------------
     * DEFAULT_CHARSET           1 (x01)
     * SYMBOL_CHARSET            2 (x02)
     * OEM_CHARSET             255 (xFF)
     * ANSI_CHARSET              0 (x00)            1252
     * RUSSIAN_CHARSET         204 (xCC)            1251
     * EE_CHARSET              238 (xEE)            1250
     * GREEK_CHARSET           161 (xA1)            1253
     * TURKISH_CHARSET         162 (xA2)            1254
     * BALTIC_CHARSET          186 (xBA)            1257
     * HEBREW_CHARSET          177 (xB1)            1255
     * ARABIC _CHARSET         178 (xB2)            1256
     * SHIFTJIS_CHARSET        128 (x80)             932
     * HANGEUL_CHARSET         129 (x81)             949
     * GB2313_CHARSET          134 (x86)             936
     * CHINESEBIG5_CHARSET     136 (x88)             950
     * </pre>
     * 
     */
    virtual QCString trRTFansicp()
    {
      return "950";
    }
    

    /*! Used as ansicpg for RTF fcharset 
     *  \see trRTFansicp() for a table of possible values.
     */
    virtual QCString trRTFCharSet()
    {
      return "136";
    }

    /*! Used as header RTF general index */
    virtual QCString trRTFGeneralIndex()
    {
      return "����";
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trClass(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("���O");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trFile(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("�ɮ�");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trNamespace(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("�R�W�Ŷ�");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGroup(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("�s��");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trPage(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("����");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trMember(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("����");
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trField(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("���");
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGlobal(bool /*first_capital*/, bool /*singular*/)
    { 
      return QCString("����");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.7
//////////////////////////////////////////////////////////////////////////

    /*! This text is generated when the \\author command is used and
     *  for the author section in man pages. */
    virtual QCString trAuthor(bool /*first_capital*/, bool /*singular*/)
    {                                                                         
      return QCString("�@��");
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.11
//////////////////////////////////////////////////////////////////////////

    /*! This text is put before the list of members referenced by a member
     */
    virtual QCString trReferences()
    {
      return "�Ѧ�";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.13
//////////////////////////////////////////////////////////////////////////

    /*! used in member documentation blocks to produce a list of 
     *  members that are implemented by this one.
     */
    virtual QCString trImplementedFromList(int numEntries)
    {
      return "��@ "+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of
     *  all members that implement this abstract member.
     */
    virtual QCString trImplementedInList(int numEntries)
    {
      return "��@�� "+trWriteList(numEntries)+".";
    }

};

#endif