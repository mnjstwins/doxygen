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

#ifndef UTIL_H
#define UTIL_H

#include "qtbc.h"
#include <qlist.h>
#include <qtextstream.h>
#include <ctype.h>

class ClassDef;
class FileDef;
class MemberList;
class NamespaceDef;
class FileNameDict;
class ArgumentList;
class OutputList;
class MemberDef;
class ExampleList;

extern void setAnchors(char id,MemberList *ml);
extern QCString fileToString(const char *name);
extern QCString dateToString(bool);
extern void linkifyText(OutputList &ol,const char *clName,const char *name,
                        const char *text);
extern bool getDefs(const QCString &scopeName,const QCString &memberName, 
                    const char *, MemberDef *&md, ClassDef *&cd,FileDef *&fd,
                    NamespaceDef *&nd);
extern bool generateRef(OutputList &ol,const char *,
                        const char *,bool inSeeBlock,const char * =0);
extern bool generateLink(OutputList &ol,const char *,
                         const char *,bool inSeeBlock,const char *);
extern void generateFileRef(OutputList &ol,const char *,
                             const char *linkTxt=0);
extern bool matchArguments(ArgumentList *,ArgumentList *,
                           const char *cl=0,const char *ns=0);
extern void mergeArguments(ArgumentList *,ArgumentList *);
extern QCString substituteClassNames(const QCString &s);
extern QCString convertSlashes(const QCString &s,bool dots=FALSE);
extern QCString substitute(const char *s,const char *src,const char *dst);
extern QCString resolveDefines(const char *n);
extern ClassDef *getClass(const char *key);
extern FileDef *findFileDef(const FileNameDict *fnDict,const char *n,
                bool &ambig);
extern void showFileDefMatches(const FileNameDict *fnDict,const char *n);
extern int guessSection(const char *name);
extern bool isId(char c);
extern QCString removeRedundantWhiteSpace(const QCString &s);
extern void startTitle(OutputList &ol,const char *fileName);
extern void endTitle(OutputList &ol,const char *fileName,const char *name);
void startFile(OutputList &ol,const char *name,
               const char *title,bool external=FALSE);
void endFile(OutputList &ol,bool external=FALSE);
void writeQuickLinks(OutputList &ol,bool compact,bool external=FALSE);
QCString argListToString(ArgumentList *al);
QCString tempArgListToString(ArgumentList *al);
QCString generateMarker(int id);
void writeExample(OutputList &ol,ExampleList *el);
void setFileNameForSections(QList<QCString> *anchorList,const char *fileName);
QCString stripAnnonymousScope(const QCString &s);
QCString stripAnnonymousNamespaceScope(const QCString &s);
QCString stripFromPath(const QCString &path);
bool rightScopeMatch(const QCString &scope, const QCString &name);
bool leftScopeMatch(const QCString &scope, const QCString &name);
void writePageRef(OutputList &ol,const char *cn,const char *mn);
QCString substituteKeywords(QCString &s,const char *title);

#endif