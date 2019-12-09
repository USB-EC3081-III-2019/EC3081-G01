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

#### * Sensor de humedad de suelo: [YL-69]
>>  El sensor de humedad del suelo o el higrómetro se usa generalmente para detectar la humedad del suelo. Por lo tanto, es perfecto para construir un sistema de riego automático o para controlar la humedad del suelo de sus plantas.El sensor está configurado por dos piezas: la placa electrónica (a la derecha) y la sonda con dos almohadillas, que detecta el contenido de agua (a la izquierda). El sensor tiene un potenciómetro incorporado para el ajuste de sensibilidad de la salida digital (D0), un LED de alimentación y un LED de salida digital


>>  El voltaje que emite el sensor cambia de acuerdo con el contenido de agua en el suelo.

>>  Cuando el suelo es:
>>  Húmedo: el voltaje de salida disminuye
>>  Seco: el voltaje de salida aumenta    

>>  <img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/soil-moisture-sensor-e1467578282801.png">
    
>>  La salida puede ser una señal digital (D0) BAJA o ALTA, dependiendo del contenido de agua. Si la humedad del suelo excede un cierto valor umbral predefinido, el módulo emite BAJO, de lo contrario, emite ALTO. El valor umbral para la señal digital se puede ajustar con el potenciómetro.

>>  La salida puede ser una señal analógica, por lo que obtendrá un valor entre 0 y 1023. 



#### * Sensor de humedad de suelo:
>>  El sensor de humedad sera capaz de establecer si el suelo esta humedo o seco, al no disponer de sesores de Humedad de sustrato en el laboratorio procederemos a crear nuestro propio sensor de humedad del suelo, tomando como base un video sencillo. Del cual logramos obtener nuestro circuito detector de humedad. 

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Circuito%20Detector%20de%20Humedad%20de%20la%20tierra.png">

>> Para este circuito nos basamos del siguiente video : https://www.youtube.com/watch?v=8Sbl-Od3x8s Donde la resistencia variable "TIERRRA" Termina representando la terra del video, mostrado.

#### * Sensor detector de lluvia: [Water Sensor]

>> El bloque sensor de agua está diseñado para la detección de agua, se puede utilizar ampliamente para detectar la lluvia, el nivel de agua e incluso las fugas adecuadas. El ladrillo se compone principalmente de tres partes: un conector de ladrillo electrónico, una resistencia de 1 MΩ y varias líneas de cables conductores desnudos.

>> Este sensor funciona al tener una serie de trazas expuestas conectadas al suelo y entrelazadas entre las huellas conectadas a tierra que son las huellas sensitivas. Las trazas del sensor tienen una resistencia pull-up débil de 1 MΩ. La resistencia elevará el valor de rastreo del sensor hasta que una gota de agua cortocircuite el rastreo del sensor hasta el rastreo conectado a tierra. Créalo o no, este circuito funcionará con los pines de E / S digitales de su Arduino o puede usarlo con los pines analógicos para detectar la cantidad de contacto inducido por el agua entre los rastros de tierra y del sensor.

>> Este elemento puede juzgar el nivel del agua con una serie de puntadas de cables paralelos expuestos para medir el tamaño de gota / agua. Este elemento puede cambiar fácilmente el tamaño del agua a señal analógica, y el valor analógico de salida se puede usar directamente en la función del programa, luego para lograr la función de alarma de nivel de agua. Este artículo tiene bajo consumo de energía y alta sensibilidad, que son las principales características de este mdoule.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/watersensor.jpg">


#### * Sensor detector de lluvia: [Detector de lluvia](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Detector%20de%20lluvia%20con%20dos%20transistores.pdf)

>> Este sensor sera capaz de detectar si ha empezado a llover fuera de nuestro invernadero con la finalidad de activar las ventanas superiores para que se rieguenlas plantas con el agua de la lluvia. Este sensor al igual que el detector de humedad del suelo, deberemos crearlo ya que no poseemos el sensor necesario para el mismo.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Detector%20de%20lluvia.png">

## Actuadores:
> Son aquellos dispositivos capaces de transformar la energía hidráulica, neumática o eléctrica en la activación de procesos con la finalidad de generar un efecto sobre un proceso automatizado. Este recibe la orden de un regulador o controlador y en función a ella genera la orden para activar un elemento final de control.

### Actuadores a utilizar:
#### * Reley Godos 831A: [Relay](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Relay_Gordoa_831A-1.pdf)

>> Es un aparato eléctrico que funciona como un interruptor, abrir y cerrar el paso de la corriente eléctrica, pero accionado eléctricamente. El relé permite abrir o cerrar contactos mediante un electroimán, por eso también se llaman relés electromagnéticos o relevador.

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/RelayGodos831A.png">

#### * Electroválvulas: [Electroválvas](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/Electrov%C3%A1lvulas%20.pdf)

>> Son dispositivos creados para regular el Flujo (On / Off) de un fluido, estan diseñadas para poder usarse con agua, gas, aire, gas combustible, entre otros. Pueden ser de dos hasta cinco vias. Dependiendo el fluido que se valla a utilizar es el material de la válvula.

>><img src="">

#### * Servomotor: [Electroválvas](https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/servomotor.pdf)

>> Son dispositivos de accionamiento para el control de precision de velicidad, par motor y precison. Constituye un mejor desempeño de precision ante accionamientos mediante convertidores de frecuencia.

>><img src="">


### Diagrama de flujo tentativo:

>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/DF02.png">





