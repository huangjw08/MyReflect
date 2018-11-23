ver0.1:对于ClassFactory::getInstance().getItemObject("XXX") 程序中始终只能有XXX的一个对象。<br><br>
ver master:对于ClassFactory::getInstance().getItemObject("XXX") 程序将存在XXX的多个对象，并用指针指向，且需要手动delete 指针。