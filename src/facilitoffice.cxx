
/*****************************************************************************
 *****************************************************************************
 *
 * Simple client application using the UnoUrlResolver service.
 *
 *****************************************************************************
 *****************************************************************************/
#include "facilitoffice.h"

#include <stdio.h>
#include <cppuhelper/bootstrap.hxx>
#include <osl/file.hxx>
#include <osl/process.h>


#include<iostream>
#include <com/sun/star/registry/SimpleRegistry.hpp>
#include <com/sun/star/registry/XSimpleRegistry.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/bridge/XUnoUrlResolver.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/sheet/XSpreadsheetDocument.hpp>
#include <com/sun/star/sheet/XSpreadsheets.hpp>
#include <com/sun/star/sheet/XSpreadsheet.hpp>
#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/view/XPrintable.hpp>
#include <com/sun/star/view/PaperOrientation.hpp>
#include <string.h>

using namespace rtl;
using namespace cppu;
using namespace com::sun::star::view;
using namespace com::sun::star::table;
using namespace com::sun::star::container;
using namespace com::sun::star::sheet;
using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::beans;
using namespace com::sun::star::bridge;
using namespace com::sun::star::frame;
using namespace com::sun::star::registry;

//============================================================================

FacilitOffice::FacilitOffice()
{
	
  evidenceType = BACKGROUND_COLOR;
	 
}




int FacilitOffice::openDocument(const char* fileName)
{
	OUString sConnectionString(RTL_CONSTASCII_USTRINGPARAM("uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager"));

// get the remote office component context
 Reference< XComponentContext > xContext( ::cppu::bootstrap() );
 
 // get the remote office service manager
 Reference< XMultiComponentFactory > xServiceManager(
     xContext->getServiceManager() );
 
 // get an instance of the remote office desktop UNO service
 // and query the XComponentLoader interface
 Reference < XComponentLoader > xComponentLoader(
     xServiceManager->createInstanceWithContext( OUString(
     RTL_CONSTASCII_USTRINGPARAM( "com.sun.star.frame.Desktop" ) ),
     xContext ), UNO_QUERY_THROW );


  

	OUString sAbsoluteDocUrl, sWorkingDir, sDocPathUrl;
	osl_getProcessWorkingDir(&sWorkingDir.pData);
	osl::FileBase::getFileURLFromSystemPath( OUString::createFromAscii(fileName), sDocPathUrl);
	osl::FileBase::getAbsoluteFileURL( sWorkingDir, sDocPathUrl, sAbsoluteDocUrl);
	
	  
	


	
	Reference< XComponent > xComponent = xComponentLoader->loadComponentFromURL(
		sAbsoluteDocUrl, OUString( RTL_CONSTASCII_USTRINGPARAM("_blank") ), 0,
		Sequence < ::com::sun::star::beans::PropertyValue >() );
	



	Reference < XTextDocument > xTextDocument (xComponent,UNO_QUERY);
	xText = xTextDocument->getText();
	//xTextCursor = xText->createTextCursor();
	//Reference < XWordCursor > xWordCursor (xTextCursor,UNO_QUERY);
	
	//Reference< XPropertySet> xCursorProps (xTextCursor,UNO_QUERY);
   
	position = 0;
	len = 0;
	xTextCursorSentence = 0;
	return 0;
}


int FacilitOffice::open(const char* fileName)
{
    OUString sDocUrl;
    xServiceManager = ooConnect();
    Reference< XInterface  > Desktop = xServiceManager->createInstance(
        OUString::createFromAscii( "com.sun.star.frame.Desktop" ));




    Reference< XComponentLoader > rComponentLoader (Desktop, UNO_QUERY);
        if( rComponentLoader.is() ){
                    cout << "XComponentloader successfully instanciated\n" ;
            }
        else
             cout <<"XComponentloader failure instanciated\n";

        osl::FileBase::getFileURLFromSystemPath(
                     OUString::createFromAscii("/home/nicola/Documenti/sindaco.odt"),sDocUrl);


cout << "PRIMA DI CARICATO\n";

        Reference< XComponent > xWriterComponent = rComponentLoader->loadComponentFromURL(
            sDocUrl,
            OUString::createFromAscii("_blank"),
            0,
            Sequence < ::com::sun::star::beans::PropertyValue >());
        cout << "CARICATO\n";
}

int FacilitOffice::connectCurrentDocument()
{


    	xServiceManager = ooConnect();

      if(xServiceManager != NULL)
      {


    	if( xServiceManager.is() ){
        	printf( "Connected sucessfully to the office\n" );
    	}
//get the desktop service using createInstance returns an XInterface type
    	Reference< XInterface  > Desktop = xServiceManager->createInstance(
    		OUString::createFromAscii( "com.sun.star.frame.Desktop" ));	
  Reference< XDesktop > xDesktop (Desktop, UNO_QUERY);
  /*Reference< XComponent >*/ xComponent = xDesktop->getCurrentComponent(); 
  Reference < XTextDocument > xTextDocument (xComponent,UNO_QUERY);
	xText = xTextDocument->getText();
	//xTextCursor = xText->createTextCursor();
	//Reference < XWordCursor > xWordCursor (xTextCursor,UNO_QUERY);
	
	//Reference< XPropertySet> xCursorProps (xTextCursor,UNO_QUERY);
   
	position = 0;
	len = 0;
	xTextCursorSentence = 0;


	/*Reference<com::sun::star::document::XEventBroadcaster> evtBroadcast (xComponent, UNO_QUERY);
	EvtListener *xEvtListener=new EvtListener();
	Reference< ::com::sun::star::document::XKeyListener > xEventListener = static_cast< ::com::sun::star::document::XKeyListener* > ( xEvtListener );

	evtBroadcast->addEventListener(xEventListener); 

*/
	return 0;
       }
  return -1;
}

Reference< XMultiServiceFactory > FacilitOffice::ooConnect()
{


  OUString sConnectionString(RTL_CONSTASCII_USTRINGPARAM("uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager"));




   	Reference< XComponentContext > rComponentContext(::cppu::defaultBootstrap_InitialComponentContext() );

  
 
   // retrieve the servicemanager from the context
   Reference< XMultiComponentFactory > rServiceManager = 
				rComponentContext->getServiceManager();
 
   // instantiate a sample service with the servicemanager.
   Reference< XInterface > rInstance =  rServiceManager->createInstanceWithContext(
         OUString::createFromAscii("com.sun.star.bridge.UnoUrlResolver" ),rComponentContext );
 
   // Query for the XUnoUrlResolver interface
   Reference< XUnoUrlResolver > rResolver( rInstance, UNO_QUERY );
   if( ! rResolver.is() ){
      printf( "Error: Couldn't instantiate com.sun.star.bridge.UnoUrlResolver service\n" );
      return NULL;
   }


  

   try {
      // resolve the uno-url
      rInstance = rResolver->resolve( OUString::createFromAscii(
         "uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager" ) );
 
   


      if( ! rInstance.is() ){
         printf( "StarOffice.ServiceManager is not exported from remote counterpart\n" );
         return NULL;
      }
 
      // query for the simpler XMultiServiceFactory interface, sufficient for scripting
      Reference< XMultiServiceFactory > rOfficeServiceManager (rInstance, UNO_QUERY);
 
      if( ! rOfficeServiceManager.is() ){
            printf( "XMultiServiceFactory interface is not exported for StarOffice.ServiceManager\n" );
            return NULL;
        }       
        return rOfficeServiceManager;
   }
   catch( Exception &e ){
      OString o = OUStringToOString( e.Message, RTL_TEXTENCODING_ASCII_US );
      printf( "Error: %s\n", o.pData->buffer );
      return NULL;
   }

   return NULL;
}

void FacilitOffice::deselect()
{
  bool ret;
	Any cw;
	cw <<= (sal_Bool)false;

	if(evidenceType == BACKGROUND_COLOR)
	{
	  
	  cw <<= (long)0xFFFFFF; 
	}
	else if(evidenceType == UNDERLINE)
	{
	  cw <<= (long)12;
	}
	else
	{
	  cw <<= (long)0x000000; 
	}


	if(xTextCursorSentence != 0)
	{
	  //cout << "CAMBIO\n";
	  Reference< XPropertySet> xCursorPropsL (xTextCursorSentence,UNO_QUERY);
	  Reference <XSentenceCursor> xSentenceCursor (xTextCursorSentence,UNO_QUERY);
	 
	  //xSentenceCursor->gotoPreviousSentence(true);
	  if(evidenceType == BACKGROUND_COLOR)
	  {
	    //cout << "BACK " << getSelectedText() << "\n";
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
	  }
	  else if(evidenceType == UNDERLINE)
	  {
	    Any c;
	    c <<= (sal_Bool)false;
	    c <<= (long) 0;
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharUnderline"),c);
	  }
	  else
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharColor"),cw);
	  xSentenceCursor->gotoPreviousSentence(true);
	  xSentenceCursor->gotoNextSentence(false);
	  
	}
}

void FacilitOffice::setBackColor(int color)
{
}

void FacilitOffice::setCharColor(long color)
{
	charColor = color;
	

}


bool FacilitOffice::moveNextWord()
{
	
    	Any cw;
  	cw <<= (sal_Bool)false;
   	

	if(evidenceType == BACKGROUND_COLOR)
	{
	  
	  cw <<= (long)0xFFFFFF; 
	}
	else if(evidenceType == UNDERLINE)
	{
	  cw <<= (long)12;
	}
	else
	{
	  cw <<= (long)0x000000; 
	}



	Reference< XTextCursor> xTextCursorL = xText->createTextCursor();
	Reference< XTextCursor> xTextCursorR = xText->createTextCursor();  
	Reference< XPropertySet> xCursorPropsL (xTextCursorL,UNO_QUERY);
	Reference< XPropertySet> xCursorPropsR (xTextCursorR,UNO_QUERY);

	
  	xTextCursorL->goRight(position , false);
	xTextCursorL->gotoStart(true);

	if(evidenceType == BACKGROUND_COLOR)
	  xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
	else if(evidenceType == UNDERLINE)
	{
	  Any c;
	  c <<= (sal_Bool)false;
	  c <<= (long) 0;
	  xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharUnderline"),c);
	}
	else
	  xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharColor"),cw);


	Reference < XWordCursor > xWordCursorLeft (xTextCursorL,UNO_QUERY);

	xTextCursorR->goRight(position , false);
	
	Reference < XWordCursor > xWordCursorR (xTextCursorR,UNO_QUERY);
	//xWordCursorLeft->gotoPreviousWord(true);
	

 	

	Reference< XTextRange > cr(xTextCursorR, UNO_QUERY) ;
              
        OUString textString = cr->getString();

	
	
	
	  //xTextCursor->goRight(position , false) ;
	  //xWordCursor->gotoNextWord(false);
	  
	  xWordCursorR->gotoNextWord(true);
	  
	  cw <<= (sal_Bool)false;
	  cw <<= charColor; 
	  //Reference < XWordCursor > xWordCursor (xTextCursor,UNO_QUERY);
	  //xWordCursor->gotoEndOfWord(true);
	  
	  Reference< XTextRange > cr1(xWordCursorR, UNO_QUERY) ;
		  // get the string
	  textString = cr1->getString();

	  OString oString = rtl::OUStringToOString( textString , /*RTL_TEXTENCODING_ASCII_US*/ RTL_TEXTENCODING_UNICODE);
	  
	  if(evidenceType == BACKGROUND_COLOR)
	    xCursorPropsR->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
	  else if(evidenceType == UNDERLINE)
	  {
	    Any c;
	    c <<= (sal_Bool)false;
	    c <<= (long) 12;
	    xCursorPropsR->setPropertyValue(OUString::createFromAscii("CharUnderline"),c);
	  }
	  else
	    xCursorPropsR->setPropertyValue(OUString::createFromAscii("CharColor"),cw);

	  selectedText = oString.getStr();

	  

	  if(oString.getLength() > 0)
	  {
	    position += oString.getLength();
	    len = oString.getLength();

	    return true;
	  }
	return false;
}

string FacilitOffice::getCurrentWord()
{
	string a;
	return a;
}

bool FacilitOffice::moveNextSentence()
{
	bool ret;
	Any cw;
	cw <<= (sal_Bool)false;

	if(evidenceType == BACKGROUND_COLOR)
	{
	  
	  cw <<= (long)0xFFFFFF; 
	}
	else if(evidenceType == UNDERLINE)
	{
	  cw <<= (long)12;
	}
	else
	{
	  cw <<= (long)0x000000; 
	}

	

	if(xTextCursorSentence == 0)
	{
	  //cout << "PRIMA \n";
	  xTextCursorSentence = xText->createTextCursor();
	}
	else
	{
	  //cout << "CAMBIO\n";
	  Reference< XPropertySet> xCursorPropsL (xTextCursorSentence,UNO_QUERY);
	  Reference <XSentenceCursor> xSentenceCursor (xTextCursorSentence,UNO_QUERY);
	 
	  //xSentenceCursor->gotoPreviousSentence(true);
	  if(evidenceType == BACKGROUND_COLOR)
	  {
	    //cout << "BACK " << getSelectedText() << "\n";
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
	  }
	  else if(evidenceType == UNDERLINE)
	  {
	    Any c;
	    c <<= (sal_Bool)false;
	    c <<= (long) 0;
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharUnderline"),c);
	  }
	  else
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharColor"),cw);
	  xSentenceCursor->gotoPreviousSentence(true);
	  xSentenceCursor->gotoNextSentence(false);
	  
	
	}
	  
	Reference< XPropertySet> xCursorPropsL (xTextCursorSentence,UNO_QUERY);
	

	Reference <XSentenceCursor> xSentenceCursor (xTextCursorSentence,UNO_QUERY);
  	
	ret = xSentenceCursor->gotoNextSentence(true);

	

	if(ret )
	{
	  cw <<= (sal_Bool)false;
	  cw <<= charColor; 
	  if(evidenceType == BACKGROUND_COLOR)
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
	  else if(evidenceType == UNDERLINE)
	  {
	    Any c;
	    c <<= (sal_Bool)false;
	    c <<= (long) 12;
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharUnderline"),c);
	  }
	  else
	    xCursorPropsL->setPropertyValue(OUString::createFromAscii("CharColor"),cw);

	  Reference< XTextRange > cr(xTextCursorSentence, UNO_QUERY) ;
		
	  OUString textString = cr->getString();

	  OString oString = rtl::OUStringToOString( textString , /*RTL_TEXTENCODING_ASCII_US*/ RTL_TEXTENCODING_UNICODE );
	  selectedText = oString.getStr();
	  
	}

	return ret;
}

string FacilitOffice::getSelectedText()
{
	
	return selectedText;
}

string FacilitOffice::vocabolario()
{

  // get the XModel interface from the component


    Reference<XModel> xModel (xComponent, UNO_QUERY);

    Reference <XController> xController = xModel->getCurrentController();


  Reference <XTextViewCursorSupplier> xViewCursorSupplier (xController, UNO_QUERY);
     
     // get the cursor 
  Reference <XTextViewCursor> xViewCursor = xViewCursorSupplier->getViewCursor();


  Reference< XTextCursor> xTextCursor = xText->createTextCursorByRange(xViewCursor->getStart());
  
  Reference < XWordCursor > xWordCursorR (xTextCursor, UNO_QUERY);
  xWordCursorR->gotoStartOfWord(false);
  xWordCursorR->gotoEndOfWord(true);
  Reference< XTextRange > cr1(xWordCursorR, UNO_QUERY);
		  
  OUString textString = cr1->getString();
  OString oString = rtl::OUStringToOString( textString ,  RTL_TEXTENCODING_UNICODE);
  
  return oString.getStr();
  
  //return "";
}

void FacilitOffice::setDefaultBackColor(int color)
{
}

void FacilitOffice::setDefaultCharColor(int color)
{
}

void FacilitOffice::setCursor(int pos)
{
}

void FacilitOffice::clearPreviousWord()
{
}

void FacilitOffice::clearPreviousPhrase()
{
}

int FacilitOffice::getPosition()
{
}

void FacilitOffice::setPosition(int position)
{
}

bool FacilitOffice::moveNext()
{
  if(scansionType == WORD)
    return moveNextWord();

  return moveNextSentence();
}

FacilitOffice::~FacilitOffice()
{
//	Reference< XComponent >::query( xMultiComponentFactoryClient )->dispose();
	// Reference< XComponent >::query( xMultiComponentFactoryClient )->dispose();
}




int SAL_CALL maino( int argc, char **argv )
{
      OUString sConnectionString(RTL_CONSTASCII_USTRINGPARAM("uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager"));



 	if (argc < 2)
	{
		printf("using: DocumentLoader <file_url> [<uno_connection_url>]\n\n"
			   "example: DocumentLoader  \"file:///e:/temp/test.odt\" \"uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager\"\n");
		exit(1);
	}
 	if (argc == 3)
	{
		sConnectionString = OUString::createFromAscii(argv[2]);        
	}





    /* Bootstraps an initial component context with service manager upon a given
       registry. This includes insertion of initial services:
       - (registry) service manager, shared lib loader,
       - simple registry, nested registry,
       - implementation registration
       - registry typedescription provider, typedescription manager (also
         installs it into cppu core)
    */


  Reference< XComponentContext > xComponentContext(
        ::cppu::defaultBootstrap_InitialComponentContext() );
    
    /* Gets the service manager instance to be used (or null). This method has
       been added for convenience, because the service manager is a often used
       object.
    */

 

	Reference< XMultiComponentFactory > xMultiComponentFactoryClient(
		xComponentContext->getServiceManager() );

    /* Creates an instance of a component which supports the services specified
       by the factory.
    */
    Reference< XInterface > xInterface =
        xMultiComponentFactoryClient->createInstanceWithContext( 
            OUString::createFromAscii( "com.sun.star.bridge.UnoUrlResolver" ),
            xComponentContext );




    Reference< XUnoUrlResolver > resolver( xInterface, UNO_QUERY );



    // Resolves the component context from the office, on the uno URL given by argv[1].
    try
    {    
        xInterface = Reference< XInterface >(resolver->resolve( sConnectionString ), UNO_QUERY );


	cout << "dopo---------------ooooooooooo";

    }
    catch ( Exception& e )
    {
	    cout << "prima---------------ooooooooooo";
		printf("Error: cannot establish a connection using '%s':\n       %s\n",
               OUStringToOString(sConnectionString, RTL_TEXTENCODING_ASCII_US).getStr(),
               OUStringToOString(e.Message, RTL_TEXTENCODING_ASCII_US).getStr());
		exit(1);        
    }
    


   if(0)
{  
   


    // gets the server component context as property of the office component factory
    Reference< XPropertySet > xPropSet( xInterface, UNO_QUERY );
    xPropSet->getPropertyValue( OUString::createFromAscii("DefaultContext") ) >>= xComponentContext;

    // gets the service manager from the office
    Reference< XMultiComponentFactory > xMultiComponentFactoryServer(
        xComponentContext->getServiceManager() );
  
    /* Creates an instance of a component which supports the services specified
       by the factory. Important: using the office component context.
    */
    Reference < XComponentLoader > xComponentLoader(
        xMultiComponentFactoryServer->createInstanceWithContext( 
            OUString( RTL_CONSTASCII_USTRINGPARAM("com.sun.star.frame.Desktop" ) ),
            xComponentContext ), UNO_QUERY );
	
    /* Loads a component specified by an URL into the specified new or existing
       frame.
    */
    OUString sAbsoluteDocUrl, sWorkingDir, sDocPathUrl;
    osl_getProcessWorkingDir(&sWorkingDir.pData);
    osl::FileBase::getFileURLFromSystemPath( OUString::createFromAscii(argv[1]), sDocPathUrl);
    osl::FileBase::getAbsoluteFileURL( sWorkingDir, sDocPathUrl, sAbsoluteDocUrl);
    
    Reference< XComponent > xComponent = xComponentLoader->loadComponentFromURL(
        sAbsoluteDocUrl, OUString( RTL_CONSTASCII_USTRINGPARAM("_blank") ), 0,
        Sequence < ::com::sun::star::beans::PropertyValue >() );

  Reference < XTextDocument > xTextDocument (xComponent,UNO_QUERY);
    Reference< XText > xText = xTextDocument->getText();
    Reference< XTextCursor> xTextCursor = xText->createTextCursor();
    //Reference < XWordCursor > xWordCursor (xTextCursor,UNO_QUERY);




   Reference< XPropertySet> xCursorProps (xTextCursor,UNO_QUERY);
    Any cw;
  cw <<= (sal_Bool)false;
   cw <<= (long)0x0000FF; 
   

  xTextCursor->goRight(1, false) ;
  xTextCursor->goRight(5, true) ;
  xCursorProps->setPropertyValue(OUString::createFromAscii("CharBackColor"),cw);
    
    sleep(10);
    Reference< XComponent >::query( xMultiComponentFactoryClient )->dispose();
}
    return 0;
}
