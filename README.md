# PROYECTO: Sistema de automatización de riego
*Este proyecto tiene como finalidad crear un sistemas de control y automatizacion del riego de un invernadero. Utilizando todos y cada uno de los conocimientos que hemos adquirido duranto los ultimos 3 años de la Carrera Tecnología Electronica en la USB, basandonos en la premisa principal de (Sensores --> Control --> Actuadores), seremos capaces de crear un sistema que simule un control total de la humedad de un imbernadero físico.*

## Integrantes del equipo
* 15-11152 Orazio Javier Portillo Gatto
* 12-06824  Bensedi Jose Acosta

# Control de riego

> El control de riego es aquel sistema que provee con agua  a las plantas de un jardín de manera tecnificada por medio de un sistema de aspersión.

> Los riegos por aspersión automatizados, son de gran ayuda en estos años. Cada vez tenemos menos tiempo para dedicarnos a nuestro jardín y necesitamos soluciones prácticas y económicas para aprovecharlo durante el día. Para ahorrar en agua el ideal es regar de noche con menor temperatura, sin viento y mayor presión de agua, lo que es casi impracticable si no se tiene un riego automático.

## Sensores:
> Son aquellos dispositivos que están capacitados para detectar acciones o estímulos externos y responder en consecuencia de dichos estímulos. Es decir, nos permiten captar la información del medio físico que nos rodea. Se encarga de medir las magnitudes físicas y transformarlas en señales eléctricas capaces de ser medidas por un microcontrolador y ser utilizadas posteriormente.

### Sensores a utilizar:
#### * Humedad y Temperatura (DHT11): [DHT11](https://naylampmechatronics.com/sensores-temperatura-y-humedad/57-sensor-de-temperatura-y-humedad-relativa-dht11.html)
>>  El DHT11 es un sensor digital de temperatura y humedad relativa de bajo costo y fácil uso. Integra un sensor capacitivo de humedad y un termistor para medir el aire circundante, y muestra los datos mediante una señal digital en el pin de datos (no posee salida analógica). Utilizado en aplicaciones académicas relacionadas al control automático de temperatura, aire acondicionado, monitoreo ambiental en agricultura y más.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/DHT11.png">

#### * Fotocelda (LDR): [LDR](https://tuelectronica.es/fotocelda-control-de-dispositivos-con-la-luz/)
>>  Una fotocelda es un dispositivo electrónico que es capaz de producir una pequeña cantidad de corriente eléctrica al ser expuesta a la luz, este dispositivo está compuesto por una fotorresistencia o resistencia LDR (componente electrónico que varía su resistencia con la luz) la cual está fabricada con un material que reacciona a la luz, de esta manera cuando este material recibe la luz cambia su resistividad.  Recordar no confundir la fotocelda con la fotorresistencia LDR, son conceptos diferentes. El primero es un dispositivo de control, y el segundo es un componente fotosensor que permite el funcionamiento del primero. 

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/foto_celda.jpg"><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/fotorresistenciaLDR.png">

#### * Sensor de humedad de suelo:
>>  El sensor de humedad sera capaz de establecer si el suelo esta humedo o seco, al no disponer de sesores de Humedad de sustrato en el laboratorio procederemos a crear nuestro propio sensor de humedad del suelo, tomando como base un video sencillo. Del cual logramos obtener nuestro circuito detector de humedad. 

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Circuito%20Detector%20de%20Humedad%20de%20la%20tierra.png">

>> Para este circuito nos basamos del siguiente video : https://www.youtube.com/watch?v=8Sbl-Od3x8s Donde la resistencia variable "TIERRRA" Termina representando la terra del video, mostrado.

#### * Sensor detector de lluvia: [Detector de lluvia](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Detector%20de%20lluvia%20con%20dos%20transistores.pdf)

>> Este sensor sera capaz de detectar si ha empezado a llover fiera de nuestro invernadero con la finalidad de activar las ventanas superiores para que se rieguenlas plantas con el agua de la lluvia. Este sensor al igual que el detector de humedad del suelo, deberemos crearlo ya que no poseemos el sensor necesario para el mismo.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Detector%20de%20lluvia.png">

## Actuadores:
> Son aquellos dispositivos capaces de transformar la energía hidráulica, neumática o eléctrica en la activación de procesos con la finalidad de generar un efecto sobre un proceso automatizado. Este recibe la orden de un regulador o controlador y en función a ella genera la orden para activar un elemento final de control.

### Actuadores a utilizar:
#### * Reley Godos 831A: [Relay](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Relay_Gordoa_831A-1.pdf)

>> Es un aparato eléctrico que funciona como un interruptor, abrir y cerrar el paso de la corriente eléctrica, pero accionado eléctricamente. El relé permite abrir o cerrar contactos mediante un electroimán, por eso también se llaman relés electromagnéticos o relevador.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/RelayGodos831A.png">


### Diagrama de flujo tentativo:

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/DF.png">





