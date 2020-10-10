#include <CkMailMan.h>
#include <CkEmail.h>

void ChilkatSample(void)
    {
    // This example requires the Chilkat API to have been previously unlocked.
    // See Global Unlock Sample for sample code.

    // The mailman object is used for sending (SMTP) and receiving (POP3) email.
    CkMailMan mailman;

    // Set the SMTP server.
    mailman.put_SmtpHost("smtp.gmail.com");

    // Set the SMTP login/password (if required)
    mailman.put_SmtpUsername("MY_SMTP_USERNAME");
    mailman.put_SmtpPassword("MY_SMTP_PASSWORD");

    // Connect to SMTP port 465 using TLS.
    mailman.put_SmtpSsl(true);
    mailman.put_SmtpPort(465);

    // Create a new email object
    CkEmail email;

    email.put_Subject("This is a test");
    email.put_Body("This is a test");
    email.put_From("Output <ms3c@sec5.org>");
    bool success = email.AddTo("Receiver","admin@gmail.com");
    // To add more recipients, call AddTo, AddCC, or AddBcc once per recipient.

    // Add some attachments.
    // The AddFileAttachment method returns the value of the content-type it chose for the attachment.
    const char *contentType = email.addFileAttachment("qa_data/txt/out.txt");
    if (email.get_LastMethodSuccess() != true) {
        std::cout << email.lastErrorText() << "\r\n";
        return;
    }

    //You can comments the std::cout's i  used them for testing purposes.
    contentType = email.addFileAttachment("qa_data/pdf/fishing.pdf");
    if (email.get_LastMethodSuccess() != true) {
        std::cout << email.lastErrorText() << "\r\n";
        return;
    }

    // Call SendEmail to connect to the SMTP server and send.
    // The connection (i.e. session) to the SMTP server remains
    // open so that subsequent SendEmail calls may use the
    // same connection.  
    success = mailman.SendEmail(email);
    if (success != true) {
        std::cout << mailman.lastErrorText() << "\r\n";
        return;
    }

    success = mailman.CloseSmtpConnection();
    if (success != true) {
        std::cout << "Connection to SMTP server not closed cleanly." << "\r\n";
    }

    std::cout << "Mail with attachments sent!" << "\r\n";
    }
