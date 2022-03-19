courseParser::courseParser()
{

}

courseParser::courseParser(QString &XMLFilePath)
    : _XMLFilePath(XMLFilePath)
{
    startParsing();
}

void courseParser::startParsing()
{
    qDebug() << "Start working with xml";

    try {
        QFile _XMLFile(_XMLFilePath);
        QXmlStreamReader _XMLReader(&_XMLFile);

        if (_XMLFile.open(QIODevice::ReadOnly))
        {
            parseXml(_XMLReader);
            _XMLFile.close();
        } else
        {
            throw error::FileNotFound;
        }

    } catch (error causedError) {
        emit somethingWentWrong(causedError);
    }

    qDebug() << "Finish working with xml";
}

void courseParser::parseXml(QXmlStreamReader &XMLReader)
{
    qDebug() << "Start parsing xml";

    while(!XMLReader.atEnd())
    {
        QString elementBuffer;
        QString content;

        XMLReader.readNext();

        _actualToken = XMLReader.tokenString();
        elementBuffer = XMLReader.name().toString();
        _actualElement = (elementBuffer == "") ? _actualElement : elementBuffer;

        content = XMLReader.text().toString();

        checkToken();

        switch (_tokens.indexOf(_actualToken)) {
        case 0:
                processStartElement();
                break;
        case 1:
                processCharacters(content);
                break;
        case 2:
                processEndElement();
                break;
        default:
                break;
        }
    }

    qDebug() << "Finish parsing xml";
}

void courseParser::checkToken()
{
    if (!_tokens.contains(_actualToken))
        throw error::CorruptedFile;
}

void courseParser::checkElement()
{
    if (!(_elements.contains(_actualElement) || _subElements.contains(_actualElement)))
        throw error::CorruptedFile;
}

void courseParser::processStartElement()
{
    checkElement();

    switch (_elements.indexOf(_actualElement)) {
    case 0: _course = new course();
            qDebug() << "\tNew course created!";
            break;
    case 1: _lesson = new lesson();
            qDebug() << "\tNew lesson created!";
            break;
    case 2: _test = new test();
            qDebug() << "\tNew test created!";
            break;
