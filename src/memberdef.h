/******************************************************************************
 *
 * $Id$
 *
 * Copyright (C) 1997-1999 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * All output generated with Doxygen is not covered by this license.
 *
 */

#ifndef MEMBERDEF_H
#define MEMBERDEF_H

#include "qtbc.h"
#include <qlist.h>
#include <qdict.h>

#include "entry.h"
#include "definition.h"

class FileDef;
class ClassDef;
class NamespaceDef;
class MemberList;
class MemberGroup;
class ExampleList;
class ExampleDict;
class OutputList;

class MemberDef : public Definition
{
  public:
    
    enum MemberType { 
      Define,
      Function, 
      Variable, 
      Typedef, 
      Enumeration, 
      EnumValue,
      Prototype,
      Signal,
      Slot,
      Friend
    };
    
    MemberDef(const char *type,const char *name,const char *args,
              const char *excp,Protection prot,Specifier virt,bool stat,
              bool related,MemberType t,const ArgumentList *tal,
              const ArgumentList *al);
   ~MemberDef(); 
    
    void writeLink(OutputList &ol,ClassDef *cd,NamespaceDef *nd,
                   FileDef *fd,MemberGroup *mg);
    void writeDeclaration(OutputList &ol,ClassDef *cd,NamespaceDef *nd,FileDef *fd,
               int prevGroupId,bool inGroup); 
    void writeDocumentation(MemberList *ml,OutputList &ol,
                            const char *scopeName,MemberType m);
    void warnIfUndocumented();
    
    QCString getOutputFileBase() const;
    const char *declaration() const      { return decl; }
    const char *definition() const       { return def; }
    const char *typeString() const       { return type; }
    const char *argsString() const       { return args; }
    const char *excpString() const       { return exception; }     
    const char *anchor() const           { return anc; }
    //QCString bodyCode() const            { return body; }
    ClassDef *memberClass()              { return classDef; }
    Protection protection() const        { return prot; }
    Specifier virtualness() const        { return virt; }
    MemberType memberType() const        { return mtype; }
    void setMemberType(MemberType t)     { mtype=t; }
    void setDefinition(const char *d)    { def=d; }
    void setDefFile(const char *f)       { defFile=f; }
    void setDefLine(int l)               { defLine=l; }
    void setFileDef(FileDef *fd)         { fileDef=fd; }
    void setFileDec(FileDef *fd)         { fileDec=fd; }
    void setAnchor(const char *a)        { anc=a; }
    void setProtection(Protection p)     { prot=p; }
    //void setBody(const QCString &b)      { body=b; }
    void setInline(bool in)              { inLine=in; }
    FileDef *getFileDef()                { return fileDef; }
    FileDef *getFileDec()                { return fileDec; }
    void setMemberClass(ClassDef *cd)    { classDef=cd; }
    bool isRelated() const               { return related; }
    bool isStatic() const                { return stat; }
    bool isInline() const                { return inLine; }
    bool hasDocumentation()  // overrides hasDocumentation in definition.h
      { return Definition::hasDocumentation(); }

    bool isLinkableInProject();
    bool isLinkable();
    
    bool detailsAreVisible() const;
    // relation to other members
    void setReimplements(MemberDef *md) { redefines=md; }
    void insertReimplementedBy(MemberDef *md);
    MemberDef  *reimplements()    { return redefines; }
    MemberList *reimplementedBy() { return redefinedBy; }
    
    // enumeration specific members
    void insertEnumField(MemberDef *md);
    void setEnumScope(MemberDef *md) { enumScope=md; }
    MemberDef *getEnumScope() const { return enumScope; }
    void setEnumDecl(OutputList &ed);
    void setEnumUsed() { eUsed=TRUE; }
    bool enumUsed() const        { return eUsed; }
    OutputList *enumDecl() const { return enumDeclList; }
    MemberList *enumFieldList()  { return enumFields; }
    void setDocumentedEnumValues(bool value) { docEnumValues=value; }
    bool hasDocumentedEnumValues() const { return docEnumValues; }
    
    // example related members
    bool addExample(const char *anchor,const char *name,const char *file);
    //void writeExample(OutputList &ol);
    bool hasExamples();
    ExampleList *getExampleList() const { return exampleList; }

    // prototype related members
    const char *getDefFile()        { return defFile; }
    int getDefLine()                { return defLine; }
    void setDecFile(const char *f)  { declFile=f; }
    void setDecLine(int l)          { defLine=l; }
    
    // convenience members
    bool isSignal() const    { return mtype==Signal;      }
    bool isSlot() const      { return mtype==Slot;        }
    bool isVariable() const  { return mtype==Variable;    }
    bool isEnumerate() const { return mtype==Enumeration; }
    bool isEnumValue() const { return mtype==EnumValue;   }
    bool isTypedef() const   { return mtype==Typedef;     }
    bool isFunction() const  { return mtype==Function;    } 
    bool isDefine() const    { return mtype==Define;      }
    bool isFriend() const    { return mtype==Friend;      }
    
    // prototype related members
    void setPrototype(bool p) { proto=p; }
    bool isPrototype() const { return proto; }
    
    // tag file related members
    //void setReference(const char *r) { external=r; } 
    //bool isReference() { return !external.isEmpty(); }

    // argument related members
    ArgumentList *argumentList() const { return argList; }
    void setArgumentList(ArgumentList *al) 
    { if (argList) delete argList;
      argList = al;
    }
    ArgumentList *templateArguments() const { return tArgList; }
    void setScopeDefTemplateArguments(ArgumentList *t);
    ArgumentList *scopeDefTemplateArguments() const { return scopeTAL; }
    void setMemberDefTemplateArguments(ArgumentList *t);
    ArgumentList *memberDefTemplateArguments() const { return membTAL; }
    //QCString getScopeTemplateNameString();
    
    // namespace related members
    NamespaceDef *getNamespace() { return nspace; }
    void setNamespace(NamespaceDef *nd) { nspace=nd; }

    // grouping related members
    void setGroupId(int groupId);
    int groupId() const          { return grpId; }
    QCString groupHeader() const { return grpHeader; }
    MemberGroup *getMemberGroup() const { return memberGroup; }
    
    void setFromAnnonymousScope(bool b) { annScope=b; }    
    void setFromAnnonymousMember(MemberDef *m) { annMemb=m; }    
    bool fromAnnonymousScope() { return annScope; }
    bool annonymousDeclShown() { return annUsed; }
    void setIndentDepth( int i) { indDepth=i; }
    int  indentDepth() { return indDepth; }
    
  private:
    ClassDef   *classDef;     // member of or related to 
    FileDef    *fileDef;      // member of file definition 
    FileDef    *fileDec;      // member of file declaration
    MemberDef  *redefines;    // the member that is redefined by this one
    MemberDef  *enumScope;    // the enclosing scope, if this is an enum field
    MemberList *redefinedBy;  // the list of members that redefine this one
    MemberDef  *memDef;       // member definition for this declaration
    MemberDef  *memDec;       // member declaration for this definition
    ExampleList *exampleList; // a list of all examples using this member
    ExampleDict *exampleDict; // a dictionary of all examples for quick access
    MemberList *enumFields;   // enumeration fields
    OutputList *enumDeclList; // stored piece of documentation for enumeration.
    NamespaceDef *nspace;     // the namespace this member is in.
    QCString type;            // return type
    QCString args;            // function arguments/variable array specifiers
    QCString exception;       // exceptions that can be thrown
    //QCString body;            // function body code
    QCString decl;            // member declaration in class
    QCString declFile;        // file where the declaration was found
    int      declLine;        // line where the declaration was found
    QCString def;             // member definition in code (fully qualified name)
    QCString defFile;         // file where the definition was found
    int      defLine;         // line where the definition was found
    QCString anc;             // HTML anchor name
    Specifier virt;           // normal/virtual/pure virtual
    Protection prot;          // protection type [Public/Protected/Private]
    bool    related;          // is this a member that is only related to a class
    bool    stat;             // is it a static function?
    bool    inLine;           // is it an inline function?
    MemberType mtype;         // returns the kind of member
    bool eUsed;               // is the enumerate already placed in a list
    bool proto;               // is it a prototype;
    bool docEnumValues;       // is an enum with documented enum values.
    bool annScope;
    bool annUsed;
    bool annShown;
    int  indDepth;
    MemberDef *annMemb;
    ArgumentList *argList;    // argument list of this member
    ArgumentList *tArgList;   // template argument list of function template
    ArgumentList *scopeTAL;   // template argument list of class template
    ArgumentList *membTAL;    // template argument list of class template
    int grpId;                // group id
    QCString grpHeader;       // group header
    MemberGroup *memberGroup; // group's member definition

    // disable copying of member defs
    MemberDef(const MemberDef &);
    MemberDef &operator=(const MemberDef &);
};

#endif