# GoF Design Pattern Catalog 23

## Creational / 生成 (5)

| No. | Pattern Name | Summary |
| -- | -- | -- |
| 1 | Abstract Factory<br>抽象工場 | Creation of related object families by abstract factory classes. Basic of creational patterns. <br> 抽象ファクトリクラスによる、関連オブジェクト群の生成。生成パターンの基本。 |
| 2 | Builder<br>建築業者 | Creation of composite objects.<br> 複合オブジェクトの作成。 |
| 3 | Factory Method<br>工場メソッド | Creation by abstract factory methods. Deferring instantiation to subclasses. <br> 抽象ファクトリメソッドによる生成。インスタンス化をサブクラスに委譲。 |
| 4 | Prototype<br>原型 | Creation by copying prototype instances. <br> 原型インスタンスのコピーによる生成。 |
| 5 | Singleton<br>単一 | Only one, single instance. <br> 唯一、単体のインスタンス。 |


<img src="catalog_GoF23_images/GoF_cr01_abstract_factory.png" alt="Abstract Factory" height="330">
<img src="catalog_GoF23_images/GoF_cr02_builder.png" alt="Builder" height="440">
<img src="catalog_GoF23_images/GoF_cr03_factory_method.png" alt="Factory Method" height="300">
<img src="catalog_GoF23_images/GoF_cr04_prototype.png" alt="Prototype" height="220">
<img src="catalog_GoF23_images/GoF_cr05_singleton.png" alt="Singleton" height="150">

## Structural / 構造 (7)

| No. | Pattern Name | Summary |
| -- | -- | -- |
| 1 | Adapter<br>適合 | Adaptation of different interfaces. <br> 異なるインターフェースの適合。 |
| 2 | Bridge<br>橋渡し | Bridge between abstract class interfaces and implementations. <br> 抽象クラスインタフェースと実装の橋渡し。 |
| 3 | Composite<br>複合体 | Composite structure of hierarchical tree representing "parts - whole." <br>『部分－全体』を表現する階層木の複合構造。 |
| 4 | Decorator<br>装飾 | Decoration of additional responsibility applied dynamically. <br>動的に適用される追加責務の装飾。 |
| 5 | Facade<br>外観 | Facade providing a unified interface to a complex subsystem. <br> 複雑なサブシステムに対し、統一インタフェースを提供する外観。 |
| 6 | Flyweight<br>軽量体 | Flyweight small objects that are shared and repeatedly used. <br> 共有され繰り返し使用される、小さな軽量オブジェクト。 |
| 7 | Proxy<br>代理人 | Proxies that respond on behalf of a heavy or time-consuming process. <br> 重い、あるいは時間を要する処理の代わりに応答する代理人。 |

<img src="catalog_GoF23_images/GoF_st01_adapter.png" alt="Adapter" height="220">
<img src="catalog_GoF23_images/GoF_st02_bridge.png" alt="Bridge" height="330">
<img src="catalog_GoF23_images/GoF_st03_composite.png" alt="Composite" height="330">
<img src="catalog_GoF23_images/GoF_st04_decorator.png" alt="Decorator" height="330">
<img src="catalog_GoF23_images/GoF_st05_facade.png" alt="Facade" height="220">
<img src="catalog_GoF23_images/GoF_st06_flyweight.png" alt="Flyweight" height="330">
<img src="catalog_GoF23_images/GoF_st07_proxy.png" alt="Proxy" height="330">

## Behavioral / 振る舞い (11)

| No. | Pattern Name | Summary |
| -- | -- | -- |
| 1 | Chain of Responsibility<br>責務連鎖 | Processes a request sequentially with connected handlers in a chain-like manner. <br> 連鎖状に接続されたハンドラ群により、要求を順次処理する。 |
| 2 | Command<br>指令 | Encapsulates requests as "command" objects. <br> 要求を「指令」オブジェクトとしてカプセル化する。 |
| 3 | Interpreter<br>言語解釈 | Represents language grammatical expressions by using hierarchical structure of "terminal" and "non-terminal" objects. This realizes language interpretation by software. <br>  言語の文法表現を「終端」と「非終端」のオブジェクトの階層構造で表現する。これによりソフトウェアによる言語解釈が可能となる。 |
| 4 | Interator<br>順次列挙 | Accesses each element of aggregated object sequentially. <br> 集約オブジェクトの要素を順に列挙する。 |
| 5 | Mediator<br>仲介 | Encapsulate object interactions into a "mediator" object. <br> オブジェクト群の相互作用を「仲介」オブジェクトにカプセル化する。 |
| 6 | Memento<br>記憶 | Externalizes an object's internal state to "memento" object and restores it later. <br> オブジェクトの内部状態を外面化して、後で戻す。 |
| 7 | Observer<br>観測 | Notifies state change to "observer". <br> 「観測者」に状態変化を通知する。 |
| 8 | State<br>状態 | Encapsulates state into "state" object. Has the "State" object itself execute behavior corresponding to the state. <br> オブジェクトの状態を「状態」オブジェクトにカプセル化する。「状態」オブジェクト自身に、状態に応じた振る舞いを実行させる。 |
| 9 | Strategy<br>戦略 | アルゴリズムのカプセル化と交換 |
| 10 | Template Method<br>雛形メソッド | 処理の骨格定義と具象化 |
| 11 | Visitor<br>訪問 | データ構造と処理の分離 |

<img src="catalog_GoF23_images/GoF_b01_chain_of_responsibility.png" alt="Adapter" height="220">
<img src="catalog_GoF23_images/GoF_b02_command.png" alt="Command" height="420">
<img src="catalog_GoF23_images/GoF_be03_interpreter.png" alt="Interpreter" height="220">
<img src="catalog_GoF23_images/GoF_be04_iterator.png" alt="Iterator" height="420">
<img src="catalog_GoF23_images/GoF_be05_mediator.png" alt="Mediator" height="280">
<img src="catalog_GoF23_images/GoF_be06_memento.png" alt="Memento" height="260">
<img src="catalog_GoF23_images/GoF_be07_observer.png" alt="Observer" height="420">
<img src="catalog_GoF23_images/GoF_be08_state.png" alt="State" height="330">
<img src="catalog_GoF23_images/GoF_be09_strategy.png" alt="Strategy" height="330">
<img src="catalog_GoF23_images/GoF_be10_template_method.png" alt="Template Method" height="280">
<img src="catalog_GoF23_images/GoF_be11_visitor.png" alt="Visitor" height="540">

## 文献
* オブジェクト指向における再利用のためのデザインパターン 改訂版, Erich Gamma / Richard Helm / Ralph Johnson / John Vlissides 著、本位田 真一 / 吉田 和樹 監訳, ソフトバンククリエイティブ(株), 1999
