# Puerta de gato

Es un diseño de una puerta automatizada para gatos que se activa mediante un pulsador. La puerta utiliza una placa Arduino como controlador principal, que se comunica con un sensor ultrasónico, un motor DC, un sensor infrarrojo y un final de carrera. Se detalla el esquema de conexión de los componentes, el código fuente del Arduino y el procedimiento de prueba de la puerta. También se incluyen diagramas del montaje y el funcionamiento. El propósito es crear una puerta que discrimine al gato de otros animales o personas. La puerta mide la distancia al objeto con el sensor ultrasónico y solo se abre si corresponde a la altura del gato. La puerta se cierra automáticamente después de un tiempo establecido, pero tiene un sistema de seguridad que evita que se cierre si hay algo debajo. La puerta se eleva con el motor DC y se detiene cuando alcanza el tope superior con el final de carrera, y se detiene en la posición inferior con el sensor infrarrojo. El gato debe ser adiestrado para pulsar el botón y accionar la puerta.

Algunos puntos importantes sobre el contenido de esta carpeta son:
- El archivo Puerta_de_Gato.ino contiene el código fuente del programa que se carga en el Arduino. El código también incluye comentarios explicativos sobre cada parte del programa.
- El archivo Puerta_de_Gato.pdf contiene el informe escrito del proyecto, que describe el objetivo, los materiales, el diseño, el funcionamiento y los resultados del mismo. El informe también incluye imágenes, diagramas y tablas que ilustran el proyecto.
- La carpeta contiene las fotografías que se tomaron durante el desarrollo. Las imágenes muestran el montaje de los componentes, el circuito eléctrico. 
- La carpeta Diagramas contiene los archivos de Proteus que se usaron para crear los diagramas del circuito eléctrico y del esquema de conexiones. Estos archivos se pueden abrir con el programa proteus, que es una herramienta de diseño de circuitos electrónicos.

# Pletismografo

Esta carpeta contiene los archivos relacionados con el proyecto de pletismografía, que consiste en medir el pulso cardiaco con electrodos. Los electrodos se conectan a un circuito que amplifica y filtra la señal eléctrica generada por el corazón. Luego, la señal se envía a un LM3914, que es un circuito integrado que puede controlar 10 LEDs para mostrar la señal en forma de barra o de punto. El LM3914 tiene una referencia interna de tensión y un divisor preciso de 10 etapas, lo que permite ajustar la escala y la sensibilidad del display. El objetivo de este proyecto es utilizar el LM3914 como un osciloscopio simple y económico para poder observar el pulso cardiaco.
# Microfono electrect
Se explica el funcionamiento de un micrófono electret, un tipo de micrófono que utiliza un diafragma electretizado para captar el sonido. El documento describe los componentes y el circuito del micrófono. También muestra cómo se realizaron los cálculos de los amplificadores. El documento es una guía práctica para realizar el montaje y la prueba del micrófono electret.

# MOC 3012

Un circuito que enciende un foco de 100w alimentado con AC a través de un opcoacoplador y un botón conectado a DC

# Amplificador no inversor

Es el amplificador no inversor, que es un circuito electrónico que amplifica la señal de entrada sin cambiar su polaridad.  El amplificador no inversor tiene varias ventajas, como una alta impedancia de entrada, una baja impedancia de salida, una buena estabilidad y un fácil ajuste de la ganancia. Se utiliza en aplicaciones como filtros, osciladores, generadores de señales y sistemas de control.
