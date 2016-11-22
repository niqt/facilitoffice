#ifndef _FACILITOFFICE_H
#define _FACILITOFFICE_H

#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <cppuhelper/bootstrap.hxx>

#include <osl/file.hxx>
#include <osl/process.h>
#include <sal/config.h>
#include <osl/interlck.h>
#include <rtl/string.h>
#include <rtl/textenc.h>
#include <sal/saldllapi.h>
#include <sal/types.h>
#include <cppu/cppudllapi.h>
#include <uno/data.h>

#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/bridge/XUnoUrlResolver.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/registry/XSimpleRegistry.hpp>

#include <com/sun/star/frame/XDesktop.hpp>

#include <com/sun/star/text/XTextDocument.hpp>
//t forget to add "com.sun.star.text.XTextDocument \" in the makefile
 #include <com/sun/star/text/XWordCursor.hpp>
 #include <com/sun/star/text/XSentenceCursor.hpp>

#include <com/sun/star/text/XTextViewCursor.hpp>
#include <com/sun/star/text/XTextViewCursorSupplier.hpp>


 #include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
// "com.sun.star.text.XWordCursor \" in the makefile
 #include <com/sun/star/beans/XPropertySet.hpp>
 #include <com/sun/star/awt/FontWeight.hpp>

#include <com/sun/star/document/XEventBroadcaster.hpp>
#include <rtl/bootstrap.h>
#include <cppuhelper/implbase1.hxx> 

#include <string>




#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/XController.hpp>



using namespace rtl;
using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::beans;
using namespace com::sun::star::bridge;
using namespace com::sun::star::frame;
using namespace com::sun::star::registry;
using namespace com::sun::star::text;
using namespace com::sun::star::beans;
using namespace com::sun::star::awt::FontWeight;
//using namespace com::sun::star::awt::XKeyListener; 

using namespace std;

/*
typedef ::cppu::WeakImplHelper1< ::com::sun::star::document::XKeyListener > EventListenerHelper;

class EvtListener : public EventListenerHelper
{
  public:
    // EvtListener(); // pb of compilation...
    //~EvtListener(); // pb of compilation...
    virtual void SAL_CALL disposing (const com::sun::star::lang::XKeyListener& aEventObj ) throw(::com::sun::star::uno::RuntimeException)
    {
      printf("object listened to will be disposed\n");
      fflush(stdout);
    }

    virtual void SAL_CALL notifyEvent(const com::sun::star::document::XKeyListener& aEvent ) throw(::com::sun::star::uno::RuntimeException)
    {
      printf("Event : %s received\n", rtl::OUStringToOString(aEvent.EventName,RTL_TEXTENCODING_ISO_8859_1).getStr());
      fflush(stdout);
    }
}; 
*/

class FacilitOffice
{
	private:
		int backColor;
		long charColor;
		int scansionType;
		//document;
		int defaultBackColor;
		int defaultCharColor;
		int position;
		int len;
		int evidenceType;
		Reference< XSimpleRegistry > xSimpleRegistry;
		Reference< XComponentContext > xComponentContext;
		Reference< XInterface > xInterface;
		Reference< XMultiComponentFactory > xMultiComponentFactoryClient;
		Reference< XText > xText;
		Reference< XTextCursor> xTextCursorSentence;
		string selectedText;
    		//Reference< XTextCursor> xTextCursor;
		Reference< XMultiServiceFactory > ooConnect();
		Reference< XComponent > xComponent;
                Reference< XMultiServiceFactory > xServiceManager;
	public:
		FacilitOffice();
		int openDocument(const char* fileName);
		int connectCurrentDocument();
		void setBackColor(int color);
		void setCharColor(long color);
		void setScansionType(int type) {scansionType = type;}
		bool moveNextWord();
		string getCurrentWord();
		bool moveNextSentence();
		string getSelectedText();
		void setDefaultBackColor(int color);
		void setDefaultCharColor(int color);
		void setCursor(int pos);
		void clearPreviousWord();
		void clearPreviousPhrase();
		int getPosition();
		void setPosition(int position);
		void setEvidencetType(int type) {evidenceType = type;}
		bool moveNext();
		void deselect();
		string vocabolario();
		~FacilitOffice();
                int open(const char *);
		enum EvidenceType {CHAR_COLOR, BACKGROUND_COLOR, UNDERLINE};
		enum ScansionType {WORD, SENTENCE};


};


int SAL_CALL maino( int argc, char **argv );

#endif
